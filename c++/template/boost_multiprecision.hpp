#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>



namespace taiton {


namespace mp = boost::multiprecision;
using cint = mp::cpp_int;
using lfloat = mp::number<mp::cpp_dec_float<30>>;


}
