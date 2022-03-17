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

        template<typename ...Args>
        inline void operator () (Args& ...args) {
                void(swallow{(void(read_(args)),false)...});
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
constexpr inline int64_t pow(int x,unsigned int y) noexcept {
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
constexpr inline int ilog10(const int64_t x) noexcept {
        int ok = 0;
        int ng = 19;
        int mid = (ok + ng)/2;

        while(ng-ok != 1){
                if(x >= pow(10,mid)){
                        ok = mid;
                }else{
                        ng = mid;
                }

                mid = (ok+ng)/2;
        }

        return ok;
}

int main(void){
}
