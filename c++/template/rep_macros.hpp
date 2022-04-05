#pragma once

#define rep_overload(i,n,m, REP, ...) REP
#define rep_0(n) for(int repeatCounter=static_cast<int>(n);repeatCounter;--repeatCounter)
#define rep_1(i,n) for(int i=0,repeatCounter=static_cast<int>(n);i < repeatCounter;++i)
#define rep_2(i,a,n) for(int i=a,repeatCounter=static_cast<int>(n);i < repeatCounter;++i)
#define rep(...) rep_overload(__VA_ARGS__,rep_2,rep_1,rep_0)(__VA_ARGS__)
#define drep_0(n) for(int i=0;i < static_cast<int>(n);++i)
#define drep_1(i,n) for(int i=0;i < static_cast<int>(n);++i)
#define drep_2(i,a,n) for(int i=static_cast<int>(n);i < static_cast<int>(n);++i)
#define drep(...) rep_overload(__VA_ARGS__,drep_2,drep_1,drep_0)(__VA_ARGS__) // 'd' means dynamic
#define fore(p,arr) for(auto& p : arr)
