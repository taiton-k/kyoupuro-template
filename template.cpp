// メイン部分(salve関数)は一番下

#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

#include <boost/range/algorithm.hpp>

#include <atcoder/modint>
#include <atcoder/math>
#include <atcoder/dsu>
//#include <atcoder/segtree>
using namespace::atcoder;
using mint = modint1000000007;
using mint2 = modint998244353;

//#define USE_MULTIPRECISION
//#define USE_BGL
//#define USE_GEOMETRY

#define rep_overload(i,n,m, REP, ...) REP
#define rep_1(i,n) for(int i=0;i < static_cast<int>(n);++i)
#define rep_2(i,a,n) for(int i=a;i < static_cast<int>(n);++i)
#define rep(...) rep_overload(__VA_ARGS__,rep_2,rep_1)(__VA_ARGS__)
#define fore(p,arr) for(auto&& p : arr)
#define endl '\n'

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
using edge = std::array<int,3>;
using graph = vec<ivec>;

constexpr char spc = ' ';

void salve();
int main(void){
        cin.tie(nullptr),ios::sync_with_stdio(false),cout << fixed << setprecision(12);
        salve();
        cout << flush;
        return 0;
}

void input(str&) noexcept;
void input(char&) noexcept;
void input(int&) noexcept;
void input(ll&) noexcept;
void input(float&) noexcept;
void input(double&) noexcept;
void input(ld&) noexcept;
template<typename T,typename U>void input(pair<T,U>&) noexcept;
template<typename T>void input(vec<T>&) noexcept;
template<typename T>void input(deq<T>&) noexcept;
template<typename... Args>void input(Args&...) noexcept;

void input(str& s) noexcept {
        int c = getchar_unlocked();

        while(c == ' ' or c == '\n'){
                c = getchar_unlocked();
        }while(!(c == ' ' or c == '\n')){
                s += c;
                c = getchar_unlocked();
        }

        ungetc(c,stdin);
}
void input(char& c) noexcept {
        c = getchar_unlocked();
        while(c == ' ' or c == '\n'){
                c = getchar_unlocked();
        }
}
void input(int& x) noexcept {
        str s;
        input(s);
        x = stoi(s);
}
void input(ll& x) noexcept {
        str s;
        input(s);
        x = stoll(s);
}
void input(float& x) noexcept {
        str s;
        input(s);
        x = stof(s);
}
void input(double& x) noexcept {
        str s;
        input(s);
        x = stod(s);
}
void input(ld& x) noexcept {
        str s;
        input(s);
        x = stold(s);
}
template<typename T>
void input(vec<T>& a) noexcept {
        fore(i,a){
                input(i);
        }
}
template<typename T>
void input(deq<T>& a) noexcept {
        fore(i,a){
                input(i);
        }
}
template<typename T,typename U>
void input(pair<T,U>& p) noexcept {
        input(p.first,p.second);
}
template<typename... Args>
void input(Args&... args) noexcept {
        void(initializer_list<int>{(input(args),0)...});
}

template<typename T>void print(const T&) noexcept;
template<typename T>void print(const vec<T>&) noexcept;
template<typename T>void print(const deq<T>&) noexcept;
template<typename T>void print(const set<T>&) noexcept;
template<typename T>void print(const mset<T>&) noexcept;
template<typename T>void print(const vec<vec<T>>&) noexcept;
template<typename... Args>void print(const Args&...) noexcept;

template<typename T>
void print(const T& a) noexcept {
        cout << a;
}

template<typename T>
void print(const vec<T>& a) noexcept {
        fore(i,a){
                print(i,spc);
        }
        print(endl);
}
template<typename T>
void print(const deq<T>& a) noexcept {
        fore(i,a){
                print(i,spc);
        }
        print(endl);
}
template<typename T>
void print(const set<T>& a) noexcept {
        fore(i,a){
                print(i,spc);
        }
        print(endl);
}
template<typename T>
void print(const mset<T>& a) noexcept {
        fore(i,a){
                print(i,spc);
        }
        print(endl);
}
template<typename T>
void print(const vec<vec<T>>& a) noexcept {
        fore(i,a){
                fore(j,i){
                        print(j,spc);
                }
                print(endl);
        }
}

template<typename... Args>
void print(const Args&... args) noexcept {
        void(initializer_list<int>{(print(args),0)...});
}

void yes() noexcept {
        cout << "Yes" << endl;
        exit(0);
        return;
}
void no() noexcept {
        cout << "No" << endl;
        exit(0);
        return;
}
void yorn(bool flag) noexcept {
        cout << (flag ? "Yes" : "No") << endl;
}


#ifdef USE_MULTIPRECISION

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;
using cint = cpp_int;
using lfloat = cpp_dec_float_50;

void input(cint x) noexcept {
        str s;
        inpiut(s);

        x.assign(s);
}

void input(cint x) noexcept {
        str s;
        inpiut(s);

        x.assign(s);
}

#endif

#ifdef USE_BGL

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
//#include <boost/graph/depth_first_search.hpp>
//#include <boost/graph/dijkstra_shortest_paths.hpp>
//#include <boost/graph/bellman_ford_shortest_paths.hpp>

using Graph = adjacency_list<vecS,vecS,directedS,no_property,property<edge_weight_t,int64_t>>;
using Vertex = graph_traits<Graph>::vertex_descriptor;

#endif

#ifdef USE_GEOMETRY

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace boost::geometry;
using point = model::d2::point_xy<long double>;
using line = model::linestring<point>;

#endif





void salve(void){

}
