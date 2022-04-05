#pragma once

#ifdef USE_BOOST
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/algorithm_ext.hpp>

#ifdef USE_BOOST_GRAPH
#include "boost_graph.hpp"
#endif

#ifdef USE_BOOST_GEOMETRY
#include "boost_geometry.hpp"
#endif

#ifdef USE_BOOST_MULTIPRECISION
#include "boost_multiprecision.hpp"
#endif

#endif
