#pragma once

#include <vector>
#include <string>
#include <set>
#include <array>
#include <deque>
#include <utility>

namespace taiton {



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
        vec():Base(){}
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
class vvec : public std::vector<std::vector<T>> {
        using Base = std::vector<std::vector<T>>;
public:
        vvec():Base(){}
        vvec(size_t n):Base(n){}
        vvec(size_t h,size_t w):Base(h,std::vector<T>(w)){}
        vvec(size_t h,size_t w,const T& init):Base(h,std::vector<T>(w,init)){}
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
template<typename T,typename U>using pset = std::set<std::pair<T,U>>;

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
