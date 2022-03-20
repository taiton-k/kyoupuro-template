// メイン部分(salve関数)は一番下

// pragmas
#ifdef LOCAL_TEST

#pragma GCC optimize("O0")

#else

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

#endif

#include <bits/stdc++.h>
using namespace std;

#include <boost/assign.hpp>
namespace bt = boost;
using namespace bt::assign;

#include <boost/range/algorithm.hpp>

// Type alias ------------------

template<typename T>using vec = vector<T>;
template<typename T>using deq = deque<T>;
template<typename T>using mset = multiset<T>;
using ll = int64_t;
using ld = long double;
using uint = unsigned int;
using ivec = vec<int>;
using llvec = vec<ll>;
using fvec = vec<float>;
using dvec = vec<double>;
using bvec = vec<bool>;
using cvec = vec<char>;
using ldvec = vec<long double>;
using str = string;
using svec = vec<str>;
using iip = pair<int,int>;
using llp = pair<ll,ll>;
using iipvec = vec<iip>;
using llpvec = vec<llp>;
using iset = set<int>;
using ideq = deq<int>;



// main function ---------------

void salve();
int main(void){
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
        salve();
        return 0;
}


//------------------------------

//#define USE_MULTIPRECISION
#ifdef USE_MULTIPRECISION

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace mp = bt::multiprecision;
using cint = cpp_int;
using lfloat = number<cpp_dec_float<12>>;

#endif

//------------------------------

//#define USE_GRAPH
#ifdef USE_GRAPH

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/breadth_first_search.hpp> // BFS
//#include <boost/graph/bipartite.hpp> // 二部グラフ判定
//#include <boost/graph/depth_first_search.hpp> // DFS
//#include <boost/graph/dijkstra_shortest_paths.hpp> // ダイクストラ
//#include <boost/graph/bellman_ford_shortest_paths.hpp> // ベルマンフォード
namespace graph = bt::graph;

using Graph = graph::adjacency_list<bt::vecS,bt::vecS,bt::undirectedS,bt::no_property,bt::property<bt::edge_weight_v,int>>;

using Vertex = graph::graph_traits<Graph>::vertex_descriptor;


void get_distance(Graph& g,Vertex from,ivec& dist){
        breadth_first_search(
                g,
                from,
                visitor(
                        make_bfs_visitor(
                                record_distances(
                                        dist.data(),
                                        on_tree_edge()
                                )
                        )
                )
        );
}

#endif

//------------------------------

//#define USE_GEOMETRY
#ifdef USE_GEOMETRY

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace gm = bt::geometry;
using point = gm::model::d2::point_xy<long double>;
using line = gm::model::linestring<point>;

#endif

//------------------------------

//#define USE_ACL
#ifdef USE_ACL

#include <atcoder/modint>
#include <atcoder/math>
#include <atcoder/dsu> // Union Find Tree
//#include <atcoder/segtree>
namespace ac = atcoder;
using atcoder::static_modint;
using mint = ac::modint1000000007;
using mint2 = ac::modint998244353;
using mivec = vec<mint>;
using mi2vec = vec<mint2>;

#endif

//------------------------------


// Utilities -------------------

template<bool B>
using enabler = enable_if_t<B,nullptr_t>;
using swallow = initializer_list<bool>;
struct call_begin {
        template<class T>void operator()(){
                std::begin(declval<T>());
        }
};
template<class T>
struct is_container
        : is_invocable<call_begin,T>
        {};

template<class T>bool is_container_v = is_container<T>::value;

template<typename T,enabler<is_integral_v<T>> = nullptr>
constexpr inline size_t ilog10(const T x) noexcept {
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

template<typename T,enabler<is_integral_v<T>> = nullptr>
constexpr inline ll sum(T a) noexcept {
        return a*(a+1)/2;
}
template<typename T,enabler<is_integral_v<T>> = nullptr>
constexpr inline ll sum(T a,T b) noexcept {
        return abs(sum(b)-sum(a-1));
}

template<typename T>
constexpr inline void chmax(T& a,T& b) noexcept {
        if(a > b){
                b = a;
        }else{
                a = b;
        }
}

template<typename T>
constexpr inline void chmin(T& a,T& b) noexcept {
        if(a > b){
                a = b;
        }else{
                b = a;
        }
}


// Input,Output functions ------

// Input class

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

        //std::unique_ptr<char[]> buffer_;
        static char buffer_[BufferSize];

        size_t readsize_ = 0;

        size_t counter_ = 0;

};
template<size_t BufferSize>
char FastInput<BufferSize>::buffer_[BufferSize];

FastInput<512*1024> input;


// Output class

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
                write(1,buffer_,counter_);
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

        template<typename T,enabler<std::is_floating_point_v<T>> = nullptr>
        inline void output(const T& a) noexcept {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(12) << a;
                output(oss.str());
        }

        template<typename T,enabler<!std::is_integral_v<T> and !std::is_floating_point_v<T> and !is_container_v<T>> = nullptr>
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
                        output('\n');
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

        //std::unique_ptr<char[]> buffer_;
        static char buffer_[BufferSize];

        size_t counter_;

};
template<size_t BufferSize>
char FastOutput<BufferSize>::buffer_[BufferSize];

FastOutput<512*1024> print;

//------------------------------

void yes() noexcept {
        print("Yes",'\n');
        exit(0);
        return;
}
void no() noexcept {
        print("No",'\n');
        exit(0);
        return;
}
void yorn(bool flag) noexcept {
        print(flag ? "Yes" : "No",'\n');
}

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
