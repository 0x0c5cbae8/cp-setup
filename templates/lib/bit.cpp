#include <templates/init>

const int mx=2e5+5;
ll bit[mx];

void add(int k, ll x){
    for(k++;k<mx;k+=k&-k) bit[k]+=x;
}

ll sum(int k){
    ll res=0;
    for(k++;k;k-=k&-k) res+=bit[k];
    return res;
}
