// メイン部分(salve関数)は一番下

// 最適化
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif
//

//# Includes ####################################################################

#include <bits/stdc++.h>
#include <unistd.h>

//#define USE_ACL
#ifdef USE_ACL
#include <atcoder/all>
#endif

#define USE_BOOST

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

//# Output Utility ##############################################################

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

//# Debug print ##################################################################

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

#else

inline void debug(...) noexcept {}

#endif

//# Utilities ####################################################################

#ifdef USE_ACL
template<int M,int O>
constexpr inline bool operator < (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() < b.val();
}
template<int M,int O>
constexpr inline bool operator > (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() > b.val();
}
template<int M,int O>
constexpr inline bool operator <= (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() <= b.val();
}
template<int M,int O>
constexpr inline bool operator >= (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() >= b.val();
}
#endif

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

constexpr inline int64_t ipow(int64_t x,int64_t y) noexcept {
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

template<typename T,typename U>
constexpr inline bool chmax(T& a,const U& b) noexcept {
        if(a < b){
                a = b;
                return true;
        }else{
                return false;
        }
}

template<typename T>
constexpr inline bool chmin(T& a,const T& b) noexcept {
        if(a > b){
                a = b;
                return true;
        }else{
                return false;
        }
}

template<typename To,typename From>
constexpr inline To cast(From&& a) noexcept {
        return static_cast<To>(a);
}


[[noreturn]] inline void yes() noexcept {
        print("Yes",'\n');
        std::exit(0);
}
[[noreturn]] inline void no() noexcept {
        print("No",'\n');
        std::exit(0);
}
inline void yorn(bool flag) noexcept {
        print(flag ? "Yes" : "No",'\n');
}

//# Own allocater ################################################################

//# Container utility ############################################################

template<class T>
class container_emplaceer {
public:
        container_emplaceer(T& cont):container_(cont){}

        template<typename ...Args>
        container_emplaceer<T>& operator () (const Args&& ...args){
                if constexpr (has_emplace_back_v<T>) {
                        container_.emplace_back(args...);
                }else if constexpr (has_emplace_v<T>) {
                        container_.emplace(args...);
                }else{
                        static_assert([]()constexpr{return false;}());
                }
                return *this;
        }

private:
        T& container_;
};

template<class T>
constexpr container_emplaceer<T> emplace(T& container){
        return container_emplaceer<T>{container};
}

//# STL Functions overload #######################################################

#ifdef USE_BOOST
}

#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>

namespace taiton{
#else

// いらなくね？
template<class Container,class Function = std::less<>>
inline auto sort(Container&& a,Function&& compare = std::less{}){return std::sort(std::begin(a),std::end(a),compare);}

template<class Container,typename T,class Function = std::less<>>
inline auto lower_bound(Container&& a,T&& x,Function&& compare = std::less{}){return std::lower_bound(std::begin(a),std::end(a),x,compare);}

template<class Container,typename T,class Function = std::less<>>
inline auto upper_bound(Container&& a,T&& x,Function&& compare = std::less{}){return std::upper_bound(std::begin(a),std::end(a),x,compare);}

template<class Container,typename T>
inline auto accumlate(Container&& a,T&& init){return std::accumulate(std::begin(a),std::end(a),init);}
template<class Container,typename T,class Function>
inline auto accumlate(Container&& a,T&& init,Function&& op){return std::accumulate(std::begin(a),std::end(a),init,op);}

#endif

//# Type alias ###################################################################

using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ldouble = long double;
using str = std::string;

//template<typename T>using vec = std::vector<T>;
template<typename T>
class vec : public std::vector<T> {
        using Base = std::vector<T>;
public:
        vec(size_t size):Base(size){}
        vec(size_t size,const T& init):Base(size,init){}
        vec(const std::initializer_list<T>& list):Base(list){}
};
using ivec = vec<int>;
using llvec = vec<ll>;
using bvec = vec<bool>;
using fvec = vec<float>;
using dvec = vec<double>;
using ldvec = vec<ldouble>;
using cvec = vec<char>;
using svec = vec<str>;
template<typename T,typename U>using pvec = vec<std::pair<T,U>>;
template<typename ...Args>using tvec = vec<std::tuple<Args...>>;

template<typename T>
class vvec : public vec<vec<T>> {
        using Base = vec<vec<T>>;
public:
        using Base::Base;
        vvec(size_t h,size_t w):Base(h,vec<T>(w)){}
        vvec(size_t h,size_t w,const T& init):Base(h,vec<T>(w,init)){}
};
using ivvec = vvec<int>;
using llvvec = vvec<ll>;
using bvvec = vvec<bool>;
using fvvec = vvec<float>;
using dvvec = vvec<double>;
using ldvvec = vvec<ldouble>;
using cvvec = vvec<char>;
using svvec = vvec<str>;
template<typename T,typename U>using pvvec = vvec<std::pair<T,U>>;
template<typename ...Args>using tvvec = vvec<std::tuple<Args...>>;

using iset = std::set<int>;
using llset = std::set<ll>;
using bset = std::set<bool>;
using fset = std::set<float>;
using dset = std::set<double>;
using ldset = std::set<ldouble>;
using cset = std::set<char>;
using sset = std::set<str>;

template<typename T>using mset = std::multiset<T>;
using imset = mset<int>;
using llmset = mset<ll>;
using bmset = mset<bool>;
using fmset = mset<float>;
using dmset = mset<double>;
using ldmset = mset<ldouble>;
using cmset = mset<char>;
using smset = mset<str>;

template<typename T>using deq = std::deque<T>;
using ideq = deq<int>;
using lldeq = deq<ll>;
using bdeq = deq<bool>;
using fdeq = deq<float>;
using ddeq = deq<double>;
using lddeq = deq<ldouble>;
using cdeq = deq<char>;
using sdeq = deq<str>;

template<typename T,size_t N>using arr = std::array<T,N>;
template<size_t N>using iarr = arr<int,N>;
template<size_t N>using llarr = arr<ll,N>;
template<size_t N>using barr = arr<bool,N>;
template<size_t N>using farr = arr<float,N>;
template<size_t N>using darr = arr<double,N>;
template<size_t N>using ldarr = arr<ldouble,N>;
template<size_t N>using carr = arr<char,N>;
template<size_t N>using sarr = arr<str,N>;

template<typename T>using initlist = std::initializer_list<T>;

#ifdef USE_ACL
using mint = atcoder::modint1000000007;
using mint2 = atcoder::modint998244353;
using mivec = vec<mint>;
using mi2vec = vec<mint2>;
#endif

}

using namespace taiton;
using namespace std;
#ifdef USE_ACL
using namespace atcoder;
#endif
#ifdef USE_BOOST
using namespace boost::range;
#endif

#define rep_overload(i,n,m, REP, ...) REP
#define rep_0(n) for(int repeatCounter=static_cast<int>(n);repeatCounter;--repeatCounter)
#define rep_1(i,n) for(int i=0,repeatCounter=static_cast<int>(n);i < repeatCounter;++i)
#define rep_2(i,a,n) for(int i=a,repeatCounter=static_cast<int>(n);i < repeatCounter;++i)
#define rep(...) rep_overload(__VA_ARGS__,rep_2,rep_1,rep_0)(__VA_ARGS__)
#define drep_0(n) for(int i=0;i < static_cast<int>(n);++i)
#define drep_1(i,n) for(int i=0;i < static_cast<int>(n);++i)
#define drep_2(i,a,n) for(int i=static_cast<int>(n);i < static_cast<int>(n);++i)
#define drep(...) rep_overload(__VA_ARGS__,drep_2,drep_1,drep_0)(__VA_ARGS__) // 'd' means dynamic
#define fore(p,arr) for(auto& p : arr)
constexpr char spc = ' ';
constexpr char lend = '\n';






void salve(void){

}
