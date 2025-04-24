#include <bits/stdc++.h>

inline unsigned long long read() {
    unsigned long long x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<48||ch>57) {
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar_unlocked();
	return x*f;
}

template<typename T>
inline void write(T x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}

