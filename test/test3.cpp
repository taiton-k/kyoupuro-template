#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


inline void in(ll& x){
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
}

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
        if(setvbuf(stdin,NULL,_IOFBF,40*1024*1024)){
                return -1;
        }
        if(setvbuf(stdout,NULL,_IOFBF,40*1024*1024)){
                return -1;
        }

        ll t;
        in(t);
        while(--t,t>=0){
                ll a,b;
                in(a),in(b);
                out(a+b);
                putchar_unlocked('\n');
        }

        return 0;
}
