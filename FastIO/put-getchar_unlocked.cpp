#include <bits/stdc++.h>

class FastInput {

public :

        template<typename... Args>
        inline void operator () (Args&... args) {
                void(swallow{(void(input(args)),false)...});
        }

private:

        using swallow = std::initializer_list<bool>;
        template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;


        inline void input(std::string& s){
                char c = getchar_unlocked();

                while(c == ' ' or c == '\n'){
                        c = getchar_unlocked();
                }while(!(c == ' ' or c == '\n')){
                        s += c;
                        c = getchar_unlocked();
                }

                ungetc(c,stdin);
        }

        inline void input(char& c){
                c = getchar_unlocked();
                while(c == ' ' or c == '\n'){
                        c = getchar_unlocked();
                }
        }

        template<typename T,enabler<std::is_integral_v<T>> = nullptr>
        inline void input(T& x){
                x = 0;
                char c;
                bool minus = false;

                do{
                        c = getchar_unlocked();
                }while(c < '0' and '9' < c and
                       c != '-' and
                       c !='+');

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
        }

        template<typename T,enabler<!std::is_integral_v<T>> = nullptr>
        inline void input(T& a){
                std::string s;
                input(s);

                std::istringstream iss(s);
                iss >> a;
        }

        template<template<class...>class T,class ...Args>
        inline void input(T<Args...>& a){
                for(auto&& i : a){
                        input(i);
                }
        }

        template<typename T,typename U>
        inline void input(std::pair<T,U>& p){
                input(p.first);
                input(p.second);
        }

} input;



class FastOutput {

public:

        template<typename... Args>
        inline void operator () (const Args&... args){
                void(swallow{(void(output(args)),false)...});
        }

private:

        using swallow = std::initializer_list<bool>;
        template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;


        inline void output(const char c){
                putchar_unlocked(c);
        }

        inline void output(const std::string& s){
                for(char c : s){
                        putchar_unlocked(c);
                }
        }

        template<typename T,enabler<std::is_integral_v<T>> = nullptr>
        inline void output(T x){
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

        template<typename T,enabler<std::is_floating_point_v<T>> = nullptr>
        inline void output(const T& a){
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(12) << a;
                out(oss.str());
        }

        template<typename T,enabler<!std::is_integral_v<T> and !std::is_floating_point_v<T>> = nullptr>
        inline void output(const T& a){
                std::ostringstream oss;
                oss << a;
                out(oss.str());
        }

        template<template<class...>class T,class...Args>
        inline void out(const T<Args...>& a){
                for(auto& i : a){
                        output(i);
                        output(' ');
                }
                output('\n');
        }

        template<template<class...>class T,template<class...>class U,class...Args,class...Brgs>
        inline void output(const T<U<Brgs...>,Args...>& a){
                for(auto& i : a){
                        for(auto& j:i){
                                output(j);
                                output(' ');
                        }
                        output('n');
                }
        }

        template<typename T,typename U>
        inline void output(const std::pair<T,U>& p){
                output(p.first);
                output(' ');
                output(p.second);
        }

        #ifdef USE_ACL
        template<int M>
        void output(static_modint<M> x){
                output(x.val());
        }
        #endif


} print;
