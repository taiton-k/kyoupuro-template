// メイン部分(salve関数)は一番下

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#include <boost/assign.hpp>
using namespace boost;
using namespace assign;

#include <boost/range/algorithm.hpp>

//#define USE_MULTIPRECISION
#ifdef USE_MULTIPRECISION

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace multiprecision;
using cint = cpp_int;
using lfloat = cpp_dec_float_50;

#endif

//#define USE_BGL
#ifdef USE_BGL

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
//#include <boost/graph/depth_first_search.hpp>
//#include <boost/graph/dijkstra_shortest_paths.hpp>
//#include <boost/graph/bellman_ford_shortest_paths.hpp>

using Graph = adjacency_list<vecS,vecS,directedS,no_property,property<edge_weight_t,int64_t>>;
using Vertex = graph_traits<Graph>::vertex_descriptor;

#endif

#include <atcoder/modint>
#include <atcoder/math>
#include <atcoder/dsu>
//#include <atcoder/segtree>
using namespace::atcoder;
using mint = modint1000000007;
using mint2 = modint998244353;

#define fore(p,arr) for(auto&& p : arr)
#define rep(i,n) for(int i=0;i < static_cast<int>(n);++i)
#define reps(i,a,n) for(int i=a;i < static_cast<int>(n);++i)
#define endl '\n'

void salve();
int main(void){
        cin.tie(nullptr),ios::sync_with_stdio(false),cout << fixed << setprecision(12);
        salve();
        cout << flush;
        return 0;
}

template<class T,typename U>
istream& operator >> (istream& is,pair<T,U>& p);

template<class T,typename U>
ostream& operator << (ostream& os,pair<T,U>& p);

template<int Mod>
ostream& operator << (ostream& os,static_modint<Mod>& n);

template<class T,typename U>
istream& operator >> (istream& is,pair<T,U>& p){
        cin >> p.first >> p.second;
        return is;
}
template<class T,typename U>
ostream& operator << (ostream& os,pair<T,U>& p){
        cout << p.first << ' ' << p.second;
        return os;
}
template<class T>
istream& operator >> (istream& is,vector<T>& arr){
        auto i = std::begin(arr), e = std::end(arr);
        while(i!=e){
                cin >> *i;
                ++i;
        }
        return is;
}
template<class T>
ostream& operator << (ostream& os,vector<T>& arr){
        auto i = std::begin(arr), e = std::end(arr);
        while(i!=e){
                cout << *i << ' ';
                ++i;
        }
        cout << endl;
        return os;
}
template<int Mod>
ostream& operator << (ostream& os,atcoder::static_modint<Mod>& n){
        cout << n.val();
        return os;
}
template<typename T>
using vec = std::vector<T>;
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
using ideq = deque<int>;
using edge = std::array<int,3>;
using graph = vec<ivec>;

constexpr char space = ' ';

void yes(){
        cout << "Yes" << endl;
        exit(0);
        return;
}
void no(){
        cout << "No" << endl;
        exit(0);
        return;
}
void yorn(bool flag){
        cout << (flag ? "Yes" : "No") << endl;
}




void salve(void){

}
