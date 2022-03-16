#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

template<bool B>
using enabler = enable_if_t<B,nullptr_t>;
using swallow = initializer_list<bool>;

class fast_io {

public:
        fast_io () {
                read(0,input_buffer_.data(),input_buffer_.size());
                input_point = input_buffer_.begin();
        }

        char* input_point;

        class fast_in {
                
        } in;

private:

        std::array<char,1024*1024> input_buffer_;

        std::array<char,1024*1024> output_buffer_;


} io;




class {

public :

        template<typename... Args>
        inline void operator () (Args&... args) {
                void(swallow{(in(args),false)...});
        }

private:

        inline void in(string& s){
                int c = getchar_unlocked();

                while(c == ' ' or c == '\n'){
                        c = getchar_unlocked();
                }while(!(c == ' ' or c == '\n')){
                        s += c;
                        c = getchar_unlocked();
                }

                putchar_unlocked(c);
        }

        inline void in(char& c){
                c = getchar_unlocked();
                while(c == ' ' or c == '\n'){
                        c = getchar_unlocked();
                }
        }

        template<typename T,enabler<is_integral_v<T>> = nullptr>
        inline void in(T& x){
                x = 0;
                int c;
                bool minus = false;

                while(c = getchar_unlocked(),c < '0' and '9' < c and c != '-' and c!='+'){}

                if(c == '-'){
                        minus = true;
                }else{
                        x += c-'0';
                }

                while(c = getchar_unlocked(),'0' <= c and c <= '9'){
                        x *= 10;
                        x += c-'0';
                }

                if(minus){
                        x *= -1;
                }

                putchar_unlocked(c);
        }

        template<typename T,enabler<!is_integral_v<T>> = nullptr>
        inline void in(T& a){
                string s;
                in(s);

                istringstream iss(s);
                iss >> a;
        }

        template<template<class...>class T,class...Args>
        inline void in(T<Args...>& a){
                for(auto&& i : a){
                        in(i);
                }
        }

        template<typename T,typename U>
        inline void in(pair<T,U>& p){
                in(p.first,p.second);
        }

} input;

class {

public:

        template<typename... Args>
        inline void operator () (const Args&... args){
                void(swallow{(out(args),false)...});
        }

private:

        inline void out(const char c){
                putchar_unlocked(c);
        }

        inline void out(const string& s){
                for(char c : s){
                        putchar_unlocked(c);
                }
        }

        template<typename T,enabler<is_integral_v<T>> = nullptr>
        inline void out(T x){
                if(x == 0){
                        putchar_unlocked('0');
                }else{
                        if(x < 0){
                                putchar_unlocked('-');
                                x *= -1;
                        }
                        T num = pow(10,static_cast<int>(log10(x)));
                        while(num != 0){
                                putchar_unlocked((x / num) + '0');

                                x %= num;
                                num /= 10;
                        }
                }
        }

        template<typename T,enabler<is_floating_point_v<T>> = nullptr>
        inline void out(const T& a){
                ostringstream oss;
                oss << fixed << setprecision(12) << a;
                out(oss.str());
        }

        template<template<class...>class T,class...Args>
        inline void out(const T<Args...>& a){
                for(auto& i : a){
                        out(i,' ');
                }
                out('\n');
        }

        template<template<class...>class T,template<class...>class U,class...Args,class...Brgs>
        inline void out(const T<U<Brgs...>,Args...>& a){
                for(auto& i : a){
                        for(auto& j:i){
                                out(j,' ');
                        }
                        out('n');
                }
        }

        template<typename T,typename U>
        inline void out(const pair<T,U>& p){
                out(p.first,' ',p.second);
        }

} print;



int main(void){

}
