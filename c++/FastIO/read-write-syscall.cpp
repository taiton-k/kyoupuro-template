#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>

//# Type traits #################################################################

using swallow = std::initializer_list<bool>;

template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;


template<class T>
struct is_container {
        template<class U>static constexpr auto check(U&& x) -> decltype(std::begin(x),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};
template<class T>constexpr bool is_container_v = is_container<T>::value;

template<class T>
struct is_multi_dimensional_container {
        template<class U>static constexpr auto check(U&&) -> decltype(typename U::value_type{},std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};
template<class T>constexpr bool is_multi_dimensional_container_v = is_multi_dimensional_container<T>::value;

template<class T>using is_one_dimensional_container = std::conjunction<is_container<T>,std::negation<is_multi_dimensional_container<T>>>;
template<class T>constexpr bool is_one_dimensional_container_v = is_one_dimensional_container<T>::value;


template<typename T,typename U>using if_integral = std::enable_if_t<std::is_integral_v<T>,U>;
template<typename T,typename U>using if_floating_point = std::enable_if_t<std::is_floating_point_v<T>,U>;
template<typename T,typename U>using if_container = std::enable_if_t<is_container_v<T>,U>;
template<typename T,typename U>using if_multi_dimensional_container = std::enable_if_t<is_multi_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_one_dimensional_container = std::enable_if_t<is_one_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_other = std::enable_if_t<!std::is_integral_v<T> and !std::is_floating_point_v<T> and !is_container_v<T>,U>;

//# Input Utility ###############################################################

template<size_t BufferSize>
class FastInput {

public:

        inline FastInput() noexcept {
        }

        template<typename ...Args>
        inline void operator () (Args& ...args) noexcept {
                void(swallow{(void(input(args)),false)...});
        }


private:

        inline void read_char(char& c) noexcept {
                if(counter_ == readsize_){
                        readsize_ = read_buf();
                        counter_ = 0;
                }

                c = buffer_[counter_];
                ++counter_;
        }

        inline int read_buf() noexcept {
                return read(0,buffer_,BufferSize);
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

                        while(read_char(c),'0' <= c and c <= '9'){
                                a *= 10;
                                a += c-'0';
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


        static char buffer_[BufferSize];

        size_t readsize_ = 0;

        size_t counter_ = 0;

};
template<size_t BufferSize>
char FastInput<BufferSize>::buffer_[BufferSize];

FastInput<1024*1024> input;

//# Output Utility ##############################################################

template<size_t BufferSize>
class FastOutput {

public:

        inline FastOutput() noexcept {
        }

        inline ~FastOutput() noexcept {
                flush();
        }

        template<typename... Args>
        inline void operator () (const Args&... args) noexcept {
                void(swallow{(void(output(args)),false)...});
        }

        inline void flush() noexcept {
                void(write(1,buffer_,counter_));
        }

private:

        inline void write_char(char c) noexcept {
                if(counter_ == BufferSize){
                        flush();
                        counter_ = 0;
                }
                buffer_[counter_] = c;
                ++counter_;
        }

        inline void write_chars(char *c,size_t s) noexcept {
                if(counter_ + s <= BufferSize){
                        memcpy(buffer_+counter_,c,BufferSize-counter_);
                        flush();
                        s -= BufferSize-counter_;
                        counter_ = 0;
                }
                memcpy(buffer_+counter_,c,s);
                counter_ += s;
        }


        inline void output(const char c) noexcept {
                write_char(c);
        }

        inline void output(const char* s) noexcept {
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
        void output(static_modint<M> x) noexcept {
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
                                for(auto&& j:i){
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

//       template<template<class...>class T,class...Args>
//       inline void output(const T<Args...>& a) noexcept {
//               for(auto&& i : a){
//                       output(i);
//                       output(' ');
//               }
//               output('\n');
//       }

//       template<template<class...>class T,template<class...>class U,class...Args,class...Brgs>
//       inline void output(const T<U<Brgs...>,Args...>& a) noexcept {
//               for(auto& i : a){
//                       for(auto&& j:i){
//                               output(j);
//                               output(' ');
//                       }
//                       output('\n');
//               }
//       }

        //std::unique_ptr<char[]> buffer_;
        static char buffer_[BufferSize];

        size_t counter_;

};
template<size_t BufferSize>
char FastOutput<BufferSize>::buffer_[BufferSize];

FastOutput<1024*1024> print;

//# Utilities ####################################################################
