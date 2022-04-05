#pragma once

#include <string>
#include <array>
#include <sstream>
#include <unistd.h>

#include "type_utilities.hpp"



namespace taiton {



template<size_t BufferSize>
class FastInput {

public:

        template<typename ...Args>
        inline void operator () (Args& ...args) noexcept {
                static_cast<void>(swallow{(input(args),false)...});
        }

        inline void update() noexcept {
                read_buf();
        }

private:

        inline void read_char(char& c) noexcept {
                if(counter_ == readsize_){
                        read_buf();
                }

                c = buffer_[counter_];
                ++counter_;
        }

        inline void read_buf() noexcept {
                readsize_ = read(0,buffer_,BufferSize);
                counter_ = 0;
        }


        inline void input(std::string& s) noexcept {
                char c;
                read_char(c);

                while(c == ' ' or c == '\n'){
                        read_char(c);
                }while(!(c == ' ' or c == '\n')){
                        s += c;
                        read_char(c);
                }
        }

        inline void input(char& c) noexcept {
                read_char(c);
                while(c == ' ' or c == '\n'){
                        read_char(c);
                }
        }

        template<typename T,size_t N>
        inline void input(std::array<T,N>& a) noexcept {
                for(auto&& i : a){
                        input(i);
                }
        }

        template<typename T,typename U>
        inline void input(std::pair<T,U>& p) noexcept {
                input(p.first);
                input(p.second);
        }

        template<typename T>
        inline void input(T& a) noexcept {
                if constexpr (std::is_integral_v<T>) {
                        a = 0;
                        char c;
                        bool minus = false;

                        do{
                                read_char(c);
                        }while(c < '0' and '9' < c and
                        c != '-' and
                        c !='+');

                        if(c == '-'){
                                minus = true;
                        }else{
                                a += c-'0';
                        }

                        read_char(c);
                        while('0' <= c and c <= '9'){
                                a *= 10;
                                a += c-'0';
                                read_char(c);
                        }

                        if(minus){
                                a *= -1;
                        }
                }else if constexpr (is_container_v<T>) {
                        for(auto&& i : a){
                                input(i);
                        }
                }else{
                        std::string s;
                        input(s);

                        std::istringstream iss(s);
                        iss >> a;
                }
        }


        static inline char buffer_[BufferSize];

        size_t readsize_ = 0;

        size_t counter_ = 0;

};
inline FastInput<1024*1024> input;



}
