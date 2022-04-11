#pragma once

#include <string>
#include <array>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <unistd.h>

#include "type_utilities.hpp"



namespace taiton {



class FastOutput {

public:

        virtual void write_char(char) noexcept = 0;
        virtual void write_chars(const char*,size_t) noexcept = 0;



        inline void output(const char c) noexcept {
                write_char(c);
        }

        inline virtual void output(const char* s) noexcept {
                while(*s != '\0'){
                        write_char(*s);
                        ++s;
                }
        }

        inline void output(const std::string& s) noexcept {
                write_chars(s.c_str(),s.size());
        }

        template<typename T,typename U>
        inline void output(const std::pair<T,U>& p) noexcept {
                output(p.first);
                output(' ');
                output(p.second);
        }

        template<typename T,size_t N>
        inline void output(std::array<T,N>& a) noexcept {
                for(auto&& i : a){
                        output(i);
                }
        }

#ifdef USE_ACL
        template<int M>
        void output(atcoder::static_modint<M> x) noexcept {
                output(x.val());
        }
#endif

        template<typename T>
        inline void output(const T& a) noexcept {
                if constexpr (std::is_integral_v<T>) {
                        T x = a;
                        if(x == 0){
                                write_char('0');
                        }else{
                                if(x < 0){
                                        write_char('-');
                                        x = -x;
                                }
                                static char num[19];
                                int i;
                                for(i=0;x!=0;++i){
                                        num[i] = '0' + x % 10;
                                        x /= 10;
                                }
                                for(;i>0;--i){
                                        write_char(num[i-1]);
                                }
                        }
                }else if constexpr (std::is_floating_point_v<T>) {
                        std::ostringstream oss;
                        oss << std::fixed << std::setprecision(12) << a;
                        output(oss.str());
                }else if constexpr (is_one_dimensional_container_v<T>) {
                        for(auto&& i : a){
                                output(i);
                                output(' ');
                        }
                        output('\n');
                }else if constexpr (is_multi_dimensional_container_v<T>) {
                        for(auto& i : a){
                                for(auto&& j : i){
                                        output(j);
                                        output(' ');
                                }
                                output('\n');
                        }
                }else{
                        std::ostringstream oss;
                        oss << a;
                        output(oss.str());
                }
        }

};



template<size_t BufferSize>
class FastStdOut : private FastOutput {

public:

        inline ~FastStdOut() noexcept {
                flush();
        }

        template<typename... Args>
        inline void operator () (const Args&... args) noexcept {
                static_cast<void>(swallow{(output(args),false)...});
        }

        inline void flush() noexcept {
                ssize_t state = write(1,buffer_,counter_);
                if(state == -1){
                        // Todo : print error state;
                        exit(errno);
                }
                counter_ = 0;
        }

private:

        inline void write_char(char c) noexcept override {
                if(counter_ == BufferSize){
                        flush();
                }
                buffer_[counter_] = c;
                ++counter_;
        }

        inline void write_chars(const char *c,size_t s) noexcept override {
                if(s != 0){
                        if(counter_ + s >= BufferSize){
                                //memcpy(buffer_+counter_,c,BufferSize-counter_);
                                flush();
                                //s -= BufferSize-counter_;
                        }
                        memcpy(buffer_+counter_,c,s);
                        counter_ += s;
                }
        }

        static inline char buffer_[BufferSize];

        size_t counter_;

};
inline FastStdOut<1024*1024> print;


#ifdef LOCAL

class FastStdErr : private FastOutput {

public:

        template<typename ...Args>
        inline void operator () (const Args& ...args) noexcept {
                output("\e[1m\e[33m");
                static_cast<void>(swallow{(output(args),false)...});
                output("\e[0m");
        }

private:

        inline void write_char(char c) noexcept override {
                ssize_t state;
                state = write(2,&c,1);
                if(state == -1){
                        std::exit(errno);
                }
        }

        inline void write_chars(const char *s,size_t len) noexcept override {
                if(s != 0){
                        ssize_t state = write(2,s,len);
                        if(state == -1){
                                std::exit(errno);
                        }
                }
        }

};
inline FastStdErr debug;

#else // #ifdef LOCAL

constexpr inline void debug(...) noexcept {}

#endif // #ifdef LOCAL



}
