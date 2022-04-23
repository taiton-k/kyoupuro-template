#include <bits/stdc++.h>



namespace taiton {


// Char to Int
constexpr inline int ctoi(char c) noexcept {
        return c-'0';
}


// にぶたん
template<typename T,typename U>
T nibutan(T left ,T right, U target,
                std::function<U(T)> func,
                std::function<bool(T,T)> equal = [](T left, T right){return right-left == 1;},
                std::function<bool(U,U)> compare = [](U res, U target){return res <= target;}){

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


using namespace std;
using ll = std::int64_t;

// ランレングス圧縮
template<class Container,typename T = typename Container::value_type>
std::vector<std::pair<T,int>> run_length_encoding (const Container& a){
        std::vector<std::pair<T,int>> rle;

        for(auto e : a){
                if((!rle.empty()) and rle.back().first == e){
                        ++rle.back().second;
                }else{
                        rle.emplace_back(e,1);
                }
        }

        return rle;
}

// 自作比較クラス
template<typename T,std::size_t I>
struct greaterAt{
        bool operator () (T left,T right){
                return left[I] < right[I];
        }
};
template<typename T,std::size_t I>
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

// return Longest Common Subsequence size
template<class Container>
int get_lcs_size(const Container& s,const Container& t){
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
template<class Container>
Container get_lcs(const Container& s,const Container& t){
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

        Container res;
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

        inline Container& data(){
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
