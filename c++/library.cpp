#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


namespace taiton {


// エラトステネスの篩
inline std::vector<bool> sieve_of_eratosthenes(std::size_t n) noexcept {
        std::vector<bool> sieve(n+1,true);

        sieve[0] = sieve[1] = false;

        for(std::size_t i = 2;i * i < n * n;i++){
                if(sieve[i] == true){
                        continue;
                }

                for(std::size_t j = 2;j * i < n;j++){
                        sieve[j * i]=false;
                }
        }

        return sieve;
}

// 約数列挙
template<typename T>
constexpr inline std::vector<T> enum_divisors(T n){
        std::vector<T> res;

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
std::vector<std::pair<int64_t,int>> prime_factorize(int64_t n){
        std::vector<std::pair<int64_t,int>> res;

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


// Char to Int
int ctoi(char c){
        return c-'0';
}

// 中央値
template<typename T>
T median(const vector<T> &v){
        T res;
        size_t cnt=v.size();
        if(cnt%2==0){
                res=(v.at(cnt/2-1)+v.at(cnt/2))/2;
        }else{
                res=v.at(cnt/2);
        }

        return res;
}

// Union-Find
class UnionFind{
        private :
                vector<int> par,rank,cnt;
                int siz;

        public :
                UnionFind(size_t n):par(n),rank(n),cnt(n,1),siz(n){
                        for(int i=0;i < n;++i){
                                par.at(i)=i;
                        }
                }

                size_t root(size_t a){
                        if(par.at(a)==a){
                                return a;
                        }else{
                                par.at(a)=root(par.at(a));
                                return par.at(a);
                        }
                }

                bool same(size_t a,size_t b){
                        return root(a)==root(b);
                }

                void unite(size_t a,size_t b){
                        a=root(a);
                        b=root(b);

                        if(a!=b){
                                if(rank.at(a) < rank.at(b))swap(a,b);

                                par.at(b)=a;

                                if(rank.at(a)==rank.at(b))++rank.at(a);

                                cnt.at(a)+=cnt.at(b);

                                --siz;
                        }
                }

                int size(size_t a){
                        return cnt.at(root(a));
                }

                int size(){
                        return siz;
                }
};

// にぶたん
template<typename T,typename U>
T nibutan(T left ,T right, U target, function<U(T)> func,
                function<bool(T,T)> equal = [](T left, T right){return right-left == 1;},
                function<bool(U,U)> compare = [](U res, U target){return res <= target;}){
        T mid = (right+left)/2;
        U res = func(mid);

        while(!equal(left,right)){
                if(compare(res,target)){
                        left = mid;
                }else{
                        right = mid;
                }

                mid = (right+left)/2;
                res = func(mid);
        }

        return left;
}

// 累積和
template<typename T>
class ruisekiwa {
        public :
                ruisekiwa(vector<T>& a){
                        v.resize(a.size()+1);

                        for(int i=1;i < v.size();++i){
                                v[i] = v[i-1]+a[i-1];
                        }
                }

                template<typename U,class V>
                ruisekiwa(vector<U>& a,V func){
                        v.resize(a.size()+1);

                        for(int i=1;i < v.size();++i){
                                if(func(a[i-1])){
                                        v[i]=v[i-1]+1;
                                }else{
                                        v[i]=v[i-1];
                                }
                        }
                }

                T range(size_t l,size_t r) const{
                        return v[r]-v[l];
                }

        private :
                vector<T> v;
};

// ランレングス圧縮
template<typename T>
vector<pair<T,int>> run_length_encoding (const vector<T>& v){
        vector<pair<T,int>> rle;

        for(int i=0;i < v.size();++i){
                if((!rle.empty()) and rle.back().first == v[i]){
                        ++rle.back().second;
                }else{
                        rle.emplace_back(v[i],1);
                }
        }

        return rle;
}
vector<pair<char,int>> run_length_encoding (const string& s){
        vector<pair<char,int>> rle;

        for(int i=0;i < static_cast<int>(s.size());++i){
                if((!rle.empty()) and rle.back().first == s[i]){
                        ++rle.back().second;
                }else{
                        rle.emplace_back(s[i],1);
                }
        }

        return rle;
}

// 自作比較クラス
template<typename T,size_t I>
struct greaterAt{
        bool operator () (T left,T right){
                return left[I] < right[I];
        }
};
template<typename T,size_t I>
struct lessAt{
        bool operator () (T left,T right){
                return left[I] > right[I];
        }
};

// トポロジカルソート
vector<int> topological_sort(vector<vector<int>>& g){
        const auto n = g.size();

        vector<int> cnt(n);
        for(auto& vertex : g){
                for(auto edge : vertex){
                        ++cnt[edge];
                }
        }

        queue<int> zero;
        for(int i=0;i < static_cast<int>(n);++i){
                if(cnt[i] == 0){
                        zero.emplace(i);
                }
        }

        vector<int> res;

        while(!zero.empty()){
                int from = zero.front();
                zero.pop();
                res.emplace_back(from+1);

                for(auto v : g[from]){
                        --cnt[v];
                        if(cnt[v] == 0){
                                zero.emplace(v);
                        }
                }
        }

        return res;
}

// Count digit
template<typename T>
int digitnum(const T a){
        return log10(a)+1;
}

// return Longest Common Subsequence size
int get_lcs_size(string& s,string& t){
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i=1;i < n+1;++i){
                for(int j=1;j < m+1;++j){
                        dp[i][j] = max({
                                dp[i-1][j],
                                dp[i][j-1],
                                dp[i-1][j-1] + (s[i-1]==t[j-1])
                        });
                }

        }

        return dp.back().back();
}

// return Longet Common Subsequence
string get_lcs(string& s,string& t){
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i=1;i < n+1;++i){
                for(int j=1;j < m+1;++j){
                        dp[i][j] = max({
                                dp[i-1][j],
                                dp[i][j-1],
                                dp[i-1][j-1] + (s[i-1]==t[j-1])
                        });
                }

        }

        string res;
        for(int i=n,j=m;dp[i][j]!=0;){
                if(dp[i-1][j] == dp[i][j-1]){
                        if(s[i-1] == t[j-1]){
                                res += s[i-1];
                                --i;
                                --j;
                        }else{
                                --i;
                        }
                }else if(dp[i-1][j] > dp[i][j-1]){
                        --i;
                }else{
                        --j;
                }
        }

        reverse(res.begin(),res.end());

        return res;
}


// Run Length Encoding
template<typename T,typename U = std::size_t,class Container = std::vector<std::pair<T,U>>>
class rle_array {

public:

        inline void push_back(T x,U n){
                if(!data_.empty() and (data_.back().first == x)){
                        data_.back().second += n;
                }else{
                        data_.emplace_back(x,n);
                }
        }

        inline void push_back(T x){
                if(!data_.empty() and (data_.back().first == x)){
                        ++data_.back().second;
                }else{
                        data_.emplace_back(x,1);
                }
        }

        inline std::vector<std::pair<T,U>> back(U n){
                std::vector<std::pair<T,U>> res;

                auto itr = data_.rbegin();

                while(n > 0 and itr != data_.rend()){
                        if(itr->second > n){
                                res.emplace_back(itr->first,itr->second - n);
                                n = 0;
                        }else{
                                res.emplace_back(*itr);
                                n -= itr->second;
                        }
                        ++itr;
                }

                return res;
        }

        inline T back(){
                return data_.back().front;
        }

        inline std::vector<std::pair<T,U>> front(U n){
                std::vector<std::pair<T,U>> res;

                auto itr = data_.begin();

                while(n > 0 and itr != data_.end()){
                        if(itr->second > n){
                                res.emplace_back(itr->first,n);
                                n = 0;
                        }else{
                                res.emplace_back(*itr);
                                n -= itr->second;
                        }
                        ++itr;
                }

                return res;
        }

        inline T front(){
                return data_.front().first;
        }

        inline void pop_back(U n){
                while(n > 0){
                        if(data_.back().second > n){
                                data_.back().second -= n;
                                n = 0;
                        }else{
                                n -= data_.back().second;
                                data_.pop_back();
                        }
                }
        }

        inline Container data(){
                return data_;
        }

protected:

        Container data_;

};

template<typename T,typename U = std::size_t>
class rle_deque : public rle_array<T,U,std::deque<std::pair<T,U>>> {
        using rle_array<T,U,std::deque<std::pair<T,U>>>::data_;

public:

        inline void push_front(T x,U n){
                if(!data_.empty() and (data_.first().first == x)){
                        data_.front().second += n;
                }else{
                        data_.emplace_front(x,n);
                }
        }

        inline void push_front(T x){
                if(!data_.empty() and (data_.front().first == x)){
                        ++data_.front().second;
                }else{
                        data_.emplace_front(x,1);
                }
        }

        inline void pop_front(U n){
                while(n > 0){
                        if(data_.front().second > n){
                                data_.front().second -= n;
                                n = 0;
                        }else{
                                n -= data_.front().second;
                                data_.pop_front();
                        }
                }
        }
};


}
