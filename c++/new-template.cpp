// メイン部分(salve関数)は一番下

// 最適化
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif
//

#include <bits/stdc++.h>
#include <unistd.h>

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


template<class T>
struct is_container {
        template<class U>static constexpr auto check(U&&) -> decltype(std::begin(std::declval<U>()),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};
template<class T>constexpr bool is_container_v = is_container<T>::value;

template<class T>
struct is_multi_dimensional_container {
        template<class U>static constexpr auto check(U&&) -> decltype(std::begin(std::declval<typename U::value_type>()),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};
template<class T>constexpr bool is_multi_dimensional_container_v = is_multi_dimensional_container<T>::value;

template<class T>using is_one_dimensional_container = std::conjunction<is_container<T>,std::negation<is_multi_dimensional_container<T>>>;
template<class T>constexpr bool is_one_dimensional_container_v = is_one_dimensional_container<T>::value;


/*
template<typename T,typename U>using if_integral = std::enable_if_t<std::is_integral_v<T>,U>;
template<typename T,typename U>using if_floating_point = std::enable_if_t<std::is_floating_point_v<T>,U>;
template<typename T,typename U>using if_container = std::enable_if_t<is_container_v<T>,U>;
template<typename T,typename U>using if_multi_dimensional_container = std::enable_if_t<is_multi_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_one_dimensional_container = std::enable_if_t<is_one_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_other = std::enable_if_t<!std::is_integral_v<T> and !std::is_floating_point_v<T> and !is_container_v<T>,U>;
*/

template<class T>
struct has_emplace_back {
        template<class U>static constexpr auto check(U&& a) -> decltype(a.emplace_back(),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};
template<class T>constexpr bool has_emplace_back_v = has_emplace_back<T>::value;

template<class T>
struct has_emplace {
        template<class U>static constexpr auto check(U&& a) -> decltype(a.emplace(),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};
template<class T>constexpr bool has_emplace_v = has_emplace<T>::value;

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

template<typename T>
constexpr inline int ilog10(const T x) noexcept {
        T cnt = 1;
        int res = 0;
        while(cnt < x){
                cnt *= 10;
                ++res;
        }
        return res;
}

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

template<typename T>
constexpr inline int64_t sum(T a) noexcept {
        return a*(a+1)/2;
}
template<typename T>
constexpr inline int64_t sum(T a,T b) noexcept {
        return abs(sum(b)-sum(a-1));
}

template<typename T>
constexpr inline void chmax(T& a,const T& b) noexcept {
        if(a < b){
                a = b;
        }
}

template<typename T>
constexpr inline void chmin(T& a,const T& b) noexcept {
        if(a > b){
                a = b;
        }
}


inline void yes() noexcept {
        print("Yes",'\n');
        exit(0);
        return;
}
inline void no() noexcept {
        print("No",'\n');
        exit(0);
        return;
}
inline void yorn(bool flag) noexcept {
        print(flag ? "Yes" : "No",'\n');
}


//# Easy push ####################################################################

template<class T>
class container_emplaceer {
public:
        container_emplaceer(T& cont):container_(cont){}

        template<typename ...Args>
        container_emplaceer<T>& operator () (Args&& ...args){
                if constexpr (has_emplace_back_v<T>) {
                        container_.emplace_back(args...);
                }else if constexpr (has_emplace_v<T>) {
                        container_.emplace(args...);
                }
                return *this;
        }

private:
        T& container_;
};

template<class T>
container_emplaceer<T> emplace(T& container){
        return container_emplaceer<T>{container};
}

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

#define rep_overload(i,n,m, REP, ...) REP
#define rep_0(n) for(int define_repeat_0=n;define_repeat_0;--define_repeat_0)
#define rep_1(i,n) for(int i=0,define_repeat_1=n;i < define_repeat_1;++i)
#define rep_2(i,a,n) for(int i=a,define_repeat_2=n;i < define_repeat_2;++i)
#define rep(...) rep_overload(__VA_ARGS__,rep_2,rep_1,rep_0)(__VA_ARGS__)
#define drep_0(n) for(int i=0;i < n;++i)
#define drep_1(i,n) for(int i=0;i < n;++i)
#define drep_2(i,a,n) for(int i=a;i < n;++i)
#define drep(...) rep_overload(__VA_ARGS__,drep_2,drep_1,drep_0)(__VA_ARGS__) // 'd' means dynamic
#define fore(p,arr) for(auto& p : arr)
constexpr char spc = ' ';
constexpr char lend = '\n';






void salve(void){

}
