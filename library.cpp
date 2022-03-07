#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

// エラトステネスの篩
void Prime(vector<bool> &prime){
        fill(prime.begin(),prime.end(),true);
        int n=prime.size();
        prime[0]=false;
        prime[1]=false;

        for(int i=0;i < sqrt(n);i++){
                if(prime[i]==true){
                        continue;
                }

                for(int j=2;j*i<n;j++){
                        prime[j*i]=false;
                }
        }

        return;
}

// Char to Int
int ctoi(char c){
        return c-'0';
}

// 素因数分解
vector<pair<ll,ll>> prime_factorize(ll n){
        vector<pair<ll,ll>> res;

        for(ll i = 2;i*i <= n;++i){
                if(n%i!=0){
                        continue;
                }

                int cnt=0;

                while(n%i==0){
                        ++cnt;
                        n/=i;
                }

                res.push_back(make_pair(i,cnt));
        }

        if(n!=1){
                res.push_back(make_pair(n,1));
        }

        return res;
}

// 2つの配列の要素と要素の差で一番小さいものを返す
// llvec x はソートされてる必要あり
template<typename T> T min_diff(const vector<T> a,const vector<T> &x){
        T num=INT_MAX/2;

        for(auto&& v : a){
                auto itr=lower_bound(all(x),v);

                if(itr==x.begin()){
                        num=min(num,(T)abs(v-*itr));
                }else{
                        num=min(num,(T)abs(v-*itr));
                        --itr;
                        num=min(num,(T)abs(v-*itr));
                }
        }

        return num;
}

// 中央値
template<typename T>T median(const vector<T> &v){
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
vector<pair<T,int>> run_length_encoding (vector<T>& v){
        vector<pair<T,int>> rle;

        for(int i=0;i < v.size();++i){
                if(rle.back().first == v[i]){
                        ++rle.back().second;
                }else{
                        rle.push_back({v[i],0});
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
void topological_sort(vector<vector<int>>& g,vector<int>& in,vector<int>& ans){
        priority_queue<int,vector<int>,greater<>> que;

        for(int i=0;i < static_cast<int>(in.size());++i){
                if(in[i]==0){
                        que.push(i);
                }
        }

        while(!que.empty()){
                int v = que.top();
                ans.push_back(v+1);
                que.pop();

                for(int& e : g[v]){
                        --in[e];
                        if(in[e]==0){
                                que.push(e);
                        }
                }
        }
}

// Fool function,but fastest(maybe)
template<typename T>
uint digitnum(const T a){
        if(a < 0){
                if(a < -100000000){
                        if(a < -1000000000000){
                                if(a < -10000000000){
                                        if(a < -1000000000){
                                                return 10;
                                        }else{
                                                return 11;
                                        }
                                }else{
                                        if(a < -100000000000){
                                                return 12;
                                        }else{
                                                return 13;
                                        }
                                }
                        }else{
                                if(a < -100000000000000){
                                        if(a < -10000000000000){
                                                return 14;
                                        }else{
                                                return 15;
                                        }
                                }else if(a < -10000000000000000){
                                        if(a < -1000000000000000){
                                                return 16;
                                        }else{
                                                return 17;
                                        }
                                }else{
                                        return log10(a)+2;
                                }
                        }
                }else{
                        if(a < -10000){
                                if(a < -100){
                                        if(a < -10){
                                                return 2;
                                        }else{
                                                return 3;
                                        }
                                }else{
                                        if(a < -1000){
                                                return 4;
                                        }else{
                                                return 5;
                                        }
                                }
                        }else{
                                if(a < -1000000){
                                        if(a < -100000){
                                                return 6;
                                        }else{
                                                return 7;
                                        }
                                }else{
                                        if(a < -10000000){
                                                return 8;
                                        }else{
                                                return 9;
                                        }
                                }
                        }
                }
        }else{
                if(a < 100000000){
                        if(a < 10000){
                                if(a < 100){
                                        if(a < 10){
                                                return 1;
                                        }else{
                                                return 2;
                                        }
                                }else{
                                        if(a < 1000){
                                                return 3;
                                        }else{
                                                return 4;
                                        }
                                }
                        }else{
                                if(a < 1000000){
                                        if(a < 100000){
                                                return 5;
                                        }else{
                                                return 6;
                                        }
                                }else{
                                        if(a < 10000000){
                                                return 7;
                                        }else{
                                                return 8;
                                        }
                                }
                        }
                }else{
                        if(a < 1000000000000){
                                if(a < 10000000000){
                                        if(a < 1000000000){
                                                return 9;
                                        }else{
                                                return 10;
                                        }
                                }else{
                                        if(a < 100000000000){
                                                return 11;
                                        }else{
                                                return 12;
                                        }
                                }
                        }else{
                                if(a < 100000000000000){
                                        if(a < 10000000000000){
                                                return 13;
                                        }else{
                                                return 14;
                                        }
                                }else if(a < 10000000000000000){
                                        if(a < 1000000000000000){
                                                return 15;
                                        }else{
                                                return 16;
                                        }
                                }else{
                                        return log10(a)+1;
                                }
                        }
                }
        }
}

