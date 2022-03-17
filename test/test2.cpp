/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
*/
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template<bool B>
using enabler = enable_if_t<B,nullptr_t>;
using swallow = initializer_list<bool>;

class FastInput {

public:

        inline FastInput(size_t buffer_size):
                buffer_(new char[buffer_size]),
                buffer_size_(buffer_size){

                read(0,buffer_.get(),buffer_size_);
        }

        template<typename... Args>
        inline void operator () (Args... args) {
                void(swallow{void((print(args),0))...});
        }

        inline void read_char (char& c) {
                c = buffer_[buffer_index_];

                if(buffer_index_ == buffer_size_-1){
                        read(0,buffer_.get(),buffer_size_);
                        buffer_index_ = 0;
                }else{
                        ++buffer_index_;
                }
        }

private:

        template<typename T,enabler<is_integral_v<T>> = nullptr>
        inline void read_ (T& x){
                x = 0;
                char c;
                bool minus = false;

                while(read_char(c),c < '0' and '9' < c and c != '-' and c!='+'){}

                if(c == '-'){
                        minus = true;
                }else{
                        x += c-'0';
                }

                while(read_char(c),'0' <= c and c <= '9'){
                        x *= 10;
                        x += c-'0';
                }

                if(minus){
                        x = -x;
                }
        }

        unique_ptr<char[]> buffer_;

        size_t buffer_size_;

        size_t buffer_index_ = 0;


};

class FastOutput {

public:

        FastOutput(size_t buffer_size):
                buffer_(new char[buffer_size]),
                buffer_size_(buffer_size){
        }

        ~FastOutput(){
                
        }

        inline void flush(){
                write(1,buffer_.get(),buffer_size_);
        }

        inline void write_char (char c) {
                c = buffer_[buffer_index_];

                if(buffer_index_ == buffer_size_-1){
                        flush();
                        buffer_index_ = 0;
                }else{
                        ++buffer_index_;
                }
        }


private:

        unique_ptr<char[]> buffer_;

        size_t buffer_size_;

        size_t buffer_index_ = 0;


};


inline void out(ll x){
        if(x == 0){
                putchar_unlocked('0');
        }else{
                if(x < 0){
                        putchar_unlocked('-');
                        x *= -1;
                }
                ll num = pow(10,static_cast<int>(log10(x)));
                while(num != 0){
                        putchar_unlocked((x / num) + '0');

                        x %= num;
                        num /= 10;
                }
        }
}






int main(void){

        char buf[10];
        read(0,
}
