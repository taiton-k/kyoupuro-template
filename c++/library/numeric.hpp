#pragma once

#include <bits/stdc++.h>

namespace taiton {


// エラトステネスの篩
inline std::vector<bool> sieve_of_eratosthenes(std::size_t n) noexcept {
        std::vector<bool> sieve(n+1,true);

        sieve[0] = sieve[1] = false;

        for(std::size_t i = 2;i * i < n * n;i++){
                if(sieve[i] == false){
                        continue;
                }

                for(std::size_t j = 2;j * i < n;j++){
                        sieve[j * i] = false;
                }
        }

        return sieve;
}

template<std::size_t N>
constexpr inline std::array<bool,N+1> sieve_of_eratosthenes() noexcept {
        std::array<bool,N+1> sieve{};
        std::fill(sieve.begin(),sieve.end(),true);

        sieve[0] = sieve[1] = false;

        for(std::size_t i = 2;i * i < N;i++){
                if(sieve[i] == false){
                        continue;
                }

                for(std::size_t j = 2;j * i < N;j++){
                        sieve[j * i] = false;
                }
        }

        return sieve;
}

// 約数列挙
inline std::vector<std::int64_t> enum_divisors(std::int64_t n) noexcept {
        std::vector<std::int64_t> res;

        for(int64_t i = 1;i * i <= n;++i){
                if(n % i == 0){
                        res.emplace_back(i);

                        if(i != n/i){
                                res.emplace_back(n/i);
                        }
                }
        }

        std::sort(res.begin(),res.end());

        return res;
}

// 素因数分解
inline std::vector<std::pair<std::int64_t,int>> prime_factorize(std::int64_t n) noexcept {
        std::vector<std::pair<std::int64_t,int>> res;

        for(int64_t i = 2;i * i <= n;++i){
                if(n % i != 0){
                        continue;
                }

                int cnt=0;

                while(n % i == 0){
                        ++cnt;
                        n /=i ;
                }

                res.emplace_back(i,cnt);
        }

        if(n!=1){
                res.emplace_back(n,1);
        }

        return res;
}

// 中央値
template<class InputIterator>
constexpr inline long double median(InputIterator begin,InputIterator end) noexcept {
        std::size_t size = std::distance(begin,end);

        if(size % 2 == 0){
                auto rItr = std::nth_element(begin,begin + size / 2,end);
                auto lItr = std::max_element(begin,rItr);

                return 1.0L * (*lItr + *rItr) / 2;
        }else{
                return 1.0L * *std::nth_element(begin,begin + size / 2,end);
        }
}

template<class Container>
constexpr inline long double median(const Container& a) noexcept {
        return median(a.begin(),a.end());
}

// 平均値
template<class InputIterator>
constexpr inline long double average(InputIterator begin,InputIterator end) noexcept {
        long double sum = 0;
        std::size_t size = 0;

        for(auto itr = begin;itr != end;++itr,++size){
                sum += *itr;
        }

        if(size == 0){
                return 0;
        }

        return sum / size;
}

template<class Container>
constexpr inline long double average(const Container& a) noexcept {
        return average(a.begin(),a.end());
}


}
