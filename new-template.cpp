// メイン部分(salve関数)は一番下

// 最適化
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx.avx2")
#endif
//

#include <bits/stdc++.h>

//# Main function ###############################################################

void salve(void);
int main(void){
        salve();
        return 0;
}



namespace taiton {

//# Type traits #################################################################

using swallow = std::initializer_list<bool>;

template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;

//####################

template<class T>
struct is_container {
        template<class U>static constexpr auto check(U&& x) -> decltype(std::begin(x),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(T{}))::value;
};
template<class T>constexpr bool is_container_v = is_container<T>::value;

template<class T>using is_multi_dimensional_container = std::conditional<is_container_v<T>,is_container<typename T::value_type>,std::false_type>;
template<class T>constexpr bool is_multi_dimensional_container_v = is_multi_dimensional_container<T>::value;

template<class T>using is_one_dimensional_container = std::conditional<is_container_v<T>, std::negation<is_container<typename T::value_type>>, std::false_type>;
template<class T>constexpr bool is_one_dimensional_container_v = is_one_dimensional_container<T>::value;

//####################

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

        template<typename T>
        inline auto input(T& x) noexcept -> if_integral<T,void> {
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

        template<typename T>
        inline auto input(T& a) noexcept -> std::enable_if_t<!std::is_integral_v<T>,void> {
                std::string s;
                input(s);

                std::istringstream iss(s);
                iss >> a;
        }

        /*
        template<template<class...>class T,class ...Args>
        inline void input(T<Args...>& a) noexcept {
                for(auto&& i : a){
                        input(i);
                }
        }
        */

        template<class T>
        inline auto input(T& a) noexcept -> if_container<T,void> {
                for(auto&& i : a){
                        input(i);
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


        inline void output(const char c) noexcept {
                write_char(c);
        }

        inline void output(const std::string& s) noexcept {
                for(char c : s){
                        write_char(c);
                }
        }

        template<typename T>
        inline auto output(T x) noexcept -> if_integral<T,void> {
                if(x == 0){
                        write_char('0');
                }else{
                        if(x < 0){
                                write_char('-');
                                x = -x;
                        }
                        char num[19];
                        int i;
                        for(i=0;x!=0;++i){
                                num[i] = '0' + x % 10;
                                x /= 10;
                        }
                        for(;i>0;--i){
                                write_char(num[i-1]);
                        }
                }
        }

        template<typename T>
        inline auto output(const T& a) noexcept -> if_floating_point<T,void> {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(12) << a;
                output(oss.str());
        }

        template<typename T>
        inline auto output(const T& a) noexcept -> if_other<T,void> {
                std::ostringstream oss;
                oss << a;
                output(oss.str());
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

        template<class T>
        inline auto output(const T& a) noexcept -> if_one_dimensional_container<T,void> {
                for(auto&& i : a){
                        output(i);
                        output(' ');
                }
                output('\n');
        }
        
        template<class T>
        inline auto output(const T& a) noexcept -> if_multi_dimensional_container<T,void> {
                for(auto& i : a){
                        for(auto&& j:i){
                                output(j);
                                output(' ');
                        }
                        output('\n');
                }
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

        //std::unique_ptr<char[]> buffer_;
        static char buffer_[BufferSize];

        size_t counter_;

};
template<size_t BufferSize>
char FastOutput<BufferSize>::buffer_[BufferSize];

FastOutput<1024*1024> print;

//# Utilities ####################################################################

//# Easy push ####################################################################

// Todo

//# Type alias ###################################################################

using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ldouble = long double;
using str = std::string;

template<typename T>using vec = std::vector<T>;
using ivec = vec<int>;
using llvec = vec<ll>;
using fvec = vec<float>;
using dvec = vec<double>;
using ldvec = vec<ldouble>;
using cvec = vec<char>;
using svec = vec<str>;

using iset = std::set<int>;
using llset = std::set<ll>;
using fset = std::set<float>;
using dset = std::set<double>;
using ldset = std::set<ldouble>;
using cset = std::set<char>;
using sset = std::set<str>;

template<typename T>using mset = std::multiset<T>;
using imset = mset<int>;
using llmset = mset<ll>;
using fmset = mset<float>;
using dmset = mset<double>;
using ldmset = mset<ldouble>;
using cmset = mset<char>;
using smset = mset<str>;

template<typename T>using deq = std::deque<T>;
using ideq = deq<int>;
using lldeq = deq<ll>;
using fdeq = deq<float>;
using ddeq = deq<double>;
using lddeq = deq<ldouble>;
using cdeq = deq<char>;
using sdeq = deq<str>;

template<typename T,size_t N>using arr = std::array<T,N>;
template<size_t N>using iarr = arr<int,N>;
template<size_t N>using llarr = arr<ll,N>;
template<size_t N>using farr = arr<float,N>;
template<size_t N>using darr = arr<double,N>;
template<size_t N>using ldarr = arr<ldouble,N>;
template<size_t N>using carr = arr<char,N>;
template<size_t N>using sarr = arr<str,N>;

}

using namespace std;
using namespace taiton;






void salve(void){

}
