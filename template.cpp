// メイン部分(salve関数)は一番下

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
using namespace boost;
using namespace boost::assign;

#include <boost/range/algorithm.hpp>

template<typename T>
using vec = std::vector<T>;
template<typename T>
using deq = std::deque<T>;
template<typename T>
using mset = std::multiset<T>;
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
using str = std::string;
using svec = vec<str>;
using iip = pair<int,int>;
using llp = pair<ll,ll>;
using iipvec = vec<iip>;
using llpvec = vec<llp>;
using ivec2 = vec<ivec>;
using iset = set<int>;
using ideq = deq<int>;

void salve();
int main(void){
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
        salve();
        return 0;
}

template<bool B>
using enabler = enable_if_t<B,nullptr_t>;
using swallow = initializer_list<bool>;


void input(str&);
void input(char&);
template<typename T,enabler<is_integral_v<T>> = nullptr>void input(T& x);
template<typename T,enabler<!is_integral_v<T>> = nullptr>void input(T& a);
template<template<class...>class T,class...Args>void input(T<Args...>&);
template<typename T,typename U>void input(pair<T,U>&);
template<typename... Args>void input(Args&...);

void input(str& s){
        int c = getchar_unlocked();

        while(c == ' ' or c == '\n'){
                c = getchar_unlocked();
        }while(!(c == ' ' or c == '\n')){
                s += c;
                c = getchar_unlocked();
        }

        ungetc(c,stdin);
}
void input(char& c){
        c = getchar_unlocked();
        while(c == ' ' or c == '\n'){
                c = getchar_unlocked();
        }
}

template<typename T,enabler<is_integral_v<T>>>
void input(T& x){
        x = 0;
        int c = getchar_unlocked();
        bool minus = false;

        while(c == ' ' or c == '\n'){
                c = getchar_unlocked();
        }while(!(c == ' ' or c == '\n')){
                if(c == '-'){
                        minus = true;
                }else if(isdigit(c)){
                        x *= 10;
                        x +  c-'0';
                }
                c = getchar_unlocked();
        }
        if(minus){
                x *= -1;
        }

        ungetc(c,stdin);
}

template<typename T,enabler<!is_integral_v<T>>>
void input(T& a){
        string s;
        input(s);

        istringstream iss(s);
        iss >> a;
}

template<template<class...>class T,class...Args>
void input(T<Args...>& a){
        for(auto& i : a){
                input(i);
        }
}

template<typename T,typename U>
void input(pair<T,U>& p){
        input(p.first,p.second);
}
template<typename... Args>
void input(Args&... args){
        void(swallow{(input(args),false)...});
}

void print(const char);
void print(const str&);
template<typename T,enabler<is_integral_v<T>> = nullptr>void print(const T&);
template<typename T,enabler<is_floating_point_v<T>> = nullptr>void print(const T&);
template<template<class...>class T,class...Args>void print(const T<Args...>&);
template<template<class...>class T,template<class...>class U,class...Args,class...Brgs>void print(const T<U<Brgs...>,Args...>&);
template<typename T,typename U>void print(const pair<T,U>& p);
template<typename... Args>void print(const Args&...);

void print(const char c){
        putchar_unlocked(c);
}

void print(const str& s){
        for(char c : s){
                putchar_unlocked(c);
        }
}

template<typename T,enabler<is_integral_v<T>>>
void print(const T& x){
        if(x < 0){
                putchar_unlocked('-');
        }
        while(x != 0){
                putchar_unlocked(x % 10 + '0');
                x /= 10;
        }
}

template<typename T,enabler<is_floating_point_v<T>>>
void print(const T& a){
        ostringstream oss;
        oss << fixed << setprecision(12) << a;
        print(oss.str());
}

template<template<class...>class T,class...Args>
void print(const T<Args...>& a){
        for(auto& i : a){
                print(i,' ');
        }
        print('\n');
}

template<template<class...>class T,template<class...>class U,class...Args,class...Brgs>
void print(const T<U<Brgs...>,Args...>& a){
        for(auto& i : a){
                for(auto& j:i){
                        print(j,' ');
                }
                print('n');
        }
}

template<typename T,typename U>
void print(const pair<T,U>& p){
        print(p.first,' ',p.second);
}

template<typename... Args>
void print(const Args&... args){
        void(swallow{(print(args),false)...});
}

template<typename T,enabler<is_integral_v<T>> = nullptr>
size_t digitnum(const T a){
        return log10(a)+1;
}

template<typename T,enabler<is_integral_v<T>> = nullptr>
ll sum(T a) noexcept {
        return a*(a+1)/2;
}
template<typename T,enabler<is_integral_v<T>> = nullptr>
ll sum(T a,T b) noexcept {
        return abs(sum(b)-sum(a-1));
}

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

//------------------------------

//#define USE_MULTIPRECISION
#ifdef USE_MULTIPRECISION

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;
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
using namespace boost::graph;

using Graph = adjacency_list<vecS,vecS,undirectedS,no_property,no_property>;
using Vertex = graph_traits<Graph>::vertex_descriptor;


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

using namespace boost::geometry;
using point = model::d2::point_xy<long double>;
using line = model::linestring<point>;

#endif

//------------------------------

//#define USE_ACL
#ifdef USE_ACL

#include <atcoder/modint>
#include <atcoder/math>
#include <atcoder/dsu> // Union Find Tree
//#include <atcoder/segtree>
using namespace::atcoder;
using mint = modint1000000007;
using mint2 = modint998244353;
using mivec = vec<mint>;
using mi2vec = vec<mint2>;

template<int M>
void print(static_modint<M> x){
        print(x.val());
}

#endif

//------------------------------

#define rep_overload(i,n,m, REP, ...) REP
#define rep_0(n) for(int define_repeat_0=n;define_repeat_0;--define_repeat_0)
#define rep_1(i,n) for(int i=0,define_repeat_1=n;i < define_repeat_1;++i)
#define rep_2(i,a,n) for(int i=a,define_repeat_2=n;i < define_repeat_2;++i)
#define rep(...) rep_overload(__VA_ARGS__,rep_2,rep_1,rep_0)(__VA_ARGS__)
#define fore(p,arr) for(auto& p : arr)
constexpr char spc = ' ';
constexpr char lend = '\n';







void salve(void){

}
