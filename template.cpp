// メイン部分(salve関数)は一番下

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#include <boost/assign.hpp>
using namespace boost;
using namespace assign;

#include <boost/range/algorithm.hpp>

/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace multiprecision;
using cint = cpp_int;
using lfloat = cpp_dec_float_50;
*/

//#include <boost/pending/disjoint_sets.hpp>
//using uf_tree = disjoint_sets_with_storage<>;

//#include <boost/graph/adjacency_list.hpp>
//#include <boost/graph/graph_utility.hpp>

#include <atcoder/modint>
#include <atcoder/math>
//#include <atcoder/segtree>
using namespace::atcoder;
using mint = modint1000000007;

#define fore(p,arr) for(auto&& p : arr)
#define rep(i,n) for(int i=0;i < static_cast<int>(n);++i)
#define reps(i,a,n) for(int i=a;i < static_cast<int>(n);++i)

void salve();
int main(void){
        cin.tie(nullptr),ios::sync_with_stdio(false),cout << fixed << setprecision(12);
        salve();
        return 0;
}

template<class T,typename U>
istream& operator >> (istream& is,pair<T,U>& p);
template<class T>
istream& operator >> (istream& is,vector<T>& arr);
template<class T>
ostream& operator << (ostream& os,vector<T>& arr);
ostream& operator << (ostream& os,mint& n);
template<class T,typename U>
istream& operator >> (istream& is,pair<T,U>& p){
        cin >> p.first >> p.second;
        return is;
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
ostream& operator << (ostream& os,mint& n){
        cout << n.val();
        return os;
}
template<typename T>
using vec = std::vector<T>;
using ll = int64_t;
using ivec = vec<int>;
using llvec = vec<ll>;
using fvec = vec<float>;
using dvec = vec<double>;
using bvec = vec<bool>;
using cvec = vec<char>;
using str = std::string;
using svec = vec<str>;
using iip = pair<int,int>;
using llp = pair<ll,ll>;
using iipvec = vec<iip>;
using llpvec = vec<llp>;
using ivec2 = vec<ivec>;
using iset = set<int>;
void yes(){
        cout << "Yes" << endl;
        return;
}
void no(){
        cout << "No" << endl;
        return;
}
void yorn(bool flag){
        cout << (flag ? "Yes" : "No") << endl;
}



void salve(void){

}
