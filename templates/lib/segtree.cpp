#include <templates/init>

const int mx=2e5+5;
ll t[4*mx];
ll a[mx];

void build(int v, int tl, int tr){
    if(tl==tr)t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v]=max(t[v*2], t[v*2+1]);
    }
}

void update(int k, ll x, int v, int tl, int tr){
    if(tl==tr)t[v]=x;
    else{
        int tm=(tl+tr)/2;
        if(k<=tm)update(k, x, v*2, tl, tm);
        else update(k, x, v*2+1, tm+1, tr);
        t[v]=max(t[v*2], t[v*2+1]);
    }
}

ll query(int l, int r, int v, int tl, int tr){
    if(r<tl||tr<l)return -1e18;
    if(l<=tl&&tr<=r)return t[v];
    int tm=(tl+tr)/2;
    return max(query(l, r, v*2, tl, tm), query(l, r, v*2+1, tm+1, tr));
}
