#pragma once

#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2")
#endif


#include <bits/stdc++.h>
#include <unistd.h>

#ifdef USE_ACL
#include <atcoder/all>
#endif

#include "template/use_boost.hpp"
#include "template/fast_input.hpp"
#include "template/fast_output.hpp"
#include "template/utilities.hpp"
#include "template/type_alias.hpp"
#include "template/macros.hpp"



void solve(void);
int main(void){

        solve();

        return 0;
}

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
