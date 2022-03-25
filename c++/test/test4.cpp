#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>


template<typename T>
void f(T&&){}

int main(void){
        const int& a = 1;
        const int& b = a;

        f(1);
        f(a);
        int v=0;
        f(v);


        return 0;
}
