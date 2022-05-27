#pragma once

#include <cmath>

#include "fast_input.hpp"
#include "fast_output.hpp"



namespace taiton {



#ifdef USE_ACL
template<int M,int O>
constexpr inline bool operator < (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() < b.val();
}
template<int M,int O>
constexpr inline bool operator > (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() > b.val();
}
template<int M,int O>
constexpr inline bool operator <= (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() <= b.val();
}
template<int M,int O>
constexpr inline bool operator >= (const atcoder::static_modint<M>& a,const atcoder::static_modint<O>& b) noexcept {
        return a.val() >= b.val();
}
#endif

constexpr int ctoi (char c) noexcept {
        return c - '0';
}

template<typename T>
constexpr inline int ilog10(T x) noexcept {
        int res = 0;
        while(x >= 10){
                x /= 10;
                ++res;
        }
        return res;
}

template<typename T>
constexpr inline int ilog2(T x) noexcept {
        int res = 0;
        while(x >= 2){
                x /= 2;
                ++res;
        }
        return res;
}

constexpr inline int64_t ipow(int64_t x,int64_t y) noexcept {
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

template<typename T>
constexpr inline int64_t sum(T a) noexcept {
        return a*(a+1)/2;
}
template<typename T>
constexpr inline int64_t sum(T a,T b) noexcept {
        int64_t res = sum(b)-sum(a-1);

        if(res >= 0){
                return res;
        }else{
                return -res;
        }
}

template<int M = 1000000007>
constexpr inline int mod_sum(int64_t a) noexcept {
        return ((a % M) * ((a+1) % M) / 2) % M;
}
template<int M = 1000000007>
constexpr inline int mod_sum(int64_t a,int64_t b) noexcept {
        if(a > b){
                std::swap(a,b);
        }

        int res = mod_sum<M>(b) - mod_sum<M>(a-1);

        return res;
}

template<typename T>
constexpr inline double rad2deg(const T& rad) noexcept {
        return rad * (180.0 / M_PI);
}

template<typename T>
constexpr inline double deg2rad(const T& deg) noexcept {
        return deg / (180.0 / M_PI);
}

template<typename T,typename U>
constexpr inline bool chmax(T& a,const U& b) noexcept {
        if(a < b){
                a = b;
                return true;
        }else{
                return false;
        }
}

template<typename T>
constexpr inline bool chmin(T& a,const T& b) noexcept {
        if(a > b){
                a = b;
                return true;
        }else{
                return false;
        }
}

template<typename To,typename From>
constexpr inline To cast(From&& a) noexcept {
        return static_cast<To>(a);
}


[[noreturn]] inline void yes() noexcept {
        print("Yes",'\n');
        std::exit(0);
}
[[noreturn]] inline void no() noexcept {
        print("No",'\n');
        std::exit(0);
}
inline void yorn(bool flag) noexcept {
        print(flag ? "Yes" : "No",'\n');
}

struct {
        template<typename T>
        constexpr operator T () {
                return std::numeric_limits<T>::min();
        }
} minusInf;

struct {
        template<typename T>
        constexpr operator T () {
                return std::numeric_limits<T>::max();
        }
        auto operator - () {
                return minusInf;
        }
} inf;


constexpr char spc = ' ';
constexpr char lend = '\n';



}
