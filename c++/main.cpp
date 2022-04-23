// メイン部分(solve関数)は一番下
// https://github.com/taiton-k/kyoupuro-template

#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2")
#endif

#define USE_ACL
#define USE_BOOST
//#define USE_BOOST_GRAPH
//#define USE_BOOST_MULTIPRECISION
//#define USE_BOOST_GEOMETRY

#include "template.hpp"
using namespace std;
using namespace taiton;
#ifdef USE_BOOST
using namespace boost;
#ifdef USE_BOOST_GRAPH
using namespace boost::graph;
#endif
#ifdef USE_BOOST_GEOMETRY
using namespace boost::geometry;
#endif
#ifdef USE_BOOST_MULTIPRECISION
using namespace boost::multiprecision;
#endif
#endif
#ifdef USE_ACL
using namespace atcoder;
#endif

//#define int ll






void solve(void){

}
