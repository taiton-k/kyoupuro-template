#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>

constexpr inline int64_t ipow(int64_t x,unsigned int y) noexcept {
        int64_t res=1;

        while(y!=0){
                if(y % 2 == 1){
                        res *= x;
                }
                y /= 2;
                x *= x;
        }

        return res;
}

constexpr inline size_t ilog10(const int64_t x) noexcept {
        int64_t cnt = 1;
        int res = 0;
        while(cnt < x){
                cnt *= 10;
                ++res;
        }
        return res;
}

template<size_t BufferSize>
class FastInput {

public:

        inline FastInput() noexcept :
                buffer_(new char[BufferSize]){
        }

        template<typename ...Args>
        inline void operator () (Args& ...args) noexcept {
                void(swallow{(void(input(args)),false)...});
        }


private:

        using swallow = std::initializer_list<bool>;
        template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;

        inline void read_char(char& c) noexcept {
                if(counter_ == readsize_){
                        readsize_ = read_buf();
                        counter_ = 0;
                }

                c = buffer_[counter_];
                ++counter_;
        }

        inline int read_buf() noexcept {
                return read(0,buffer_.get(),BufferSize);
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

        template<typename T,enabler<std::is_integral_v<T>> = nullptr>
        inline void input(T& x) noexcept {
                x = 0;
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
                        x += c-'0';
                }

                while(read_char(c),'0' <= c and c <= '9'){
                        x *= 10;
                        x += c-'0';
                }

                if(minus){
                        x *= -1;
                }
        }

        template<typename T,enabler<!std::is_integral_v<T>> = nullptr>
        inline void input(T& a) noexcept {
                std::string s;
                input(s);

                std::istringstream iss(s);
                iss >> a;
        }

        template<template<class...>class T,class ...Args>
        inline void input(T<Args...>& a) noexcept {
                for(auto&& i : a){
                        input(i);
                }
        }

        template<typename T,typename U>
        inline void input(std::pair<T,U>& p) noexcept {
                input(p.first);
                input(p.second);
        }

        std::unique_ptr<char[]> buffer_;

        size_t readsize_ = 0;

        size_t counter_ = 0;

};
FastInput<512*1024> input;



template<size_t BufferSize>
class FastOutput {

public:

        inline FastOutput() noexcept :
                buffer_(new char[BufferSize]){
        }

        inline ~FastOutput() noexcept {
                flush();
        }

        template<typename... Args>
        inline void operator () (const Args&... args) noexcept {
                void(swallow{(void(output(args)),false)...});
        }

        inline void flush() noexcept {
                write(1,buffer_.get(),counter_);
        }

private:

        using swallow = std::initializer_list<bool>;
        template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;

        inline void write_char(char c) noexcept {
                if(counter_ == BufferSize){
                        flush();
                        counter_ = 0;
                }
                buffer_[counter_] = c;
                ++counter_;
        }


        inline void output(const char c) noexcept {
                write_char(c);
        }

        inline void output(const std::string& s) noexcept {
                for(char c : s){
                        write_char(c);
                }
        }

        template<typename T,enabler<std::is_integral_v<T>> = nullptr>
        inline void output(T x) noexcept {
                if(x == 0){
                        write_char('0');
                }else{
                        if(x < 0){
                                write_char('-');
                                x *= -1;
                        }
                        T num = pow(10,static_cast<int>(log10(x)));
                        while(num != 0){
                                write_char((x / num) + '0');

                                x %= num;
                                num /= 10;
                        }
                }
        }

        template<typename T,enabler<std::is_floating_point_v<T>> = nullptr>
        inline void output(const T& a) noexcept {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(12) << a;
                output(oss.str());
        }

        template<typename T,enabler<!std::is_integral_v<T> and !std::is_floating_point_v<T>> = nullptr>
        inline void output(const T& a) noexcept {
                std::ostringstream oss;
                oss << a;
                output(oss.str());
        }

        template<template<class...>class T,class...Args>
        inline void out(const T<Args...>& a) noexcept {
                for(auto& i : a){
                        output(i);
                        output(' ');
                }
                output('\n');
        }

        template<template<class...>class T,template<class...>class U,class...Args,class...Brgs>
        inline void output(const T<U<Brgs...>,Args...>& a) noexcept {
                for(auto& i : a){
                        for(auto& j:i){
                                output(j);
                                output(' ');
                        }
                        output('n');
                }
        }

        template<typename T,typename U>
        inline void output(const std::pair<T,U>& p) noexcept {
                output(p.first);
                output(' ');
                output(p.second);
        }

        #ifdef USE_ACL
        template<int M>
        void output(static_modint<M> x) noexcept {
                output(x.val());
        }
        #endif

        std::unique_ptr<char[]> buffer_;

        size_t counter_;

};
FastOutput<512*1024> print;
