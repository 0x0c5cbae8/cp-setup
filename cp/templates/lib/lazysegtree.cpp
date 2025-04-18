#include <templates/init>

const int mx=2e5+5;
struct node{
    ll s, lz;
    int sz;
} t[4*mx];
ll a[mx];

void apply(int v, ll x){
    t[v].s+=x*t[v].sz;
    t[v].lz+=x;
}

void push(int v){
    apply(v*2, t[v].lz);
    apply(v*2+1, t[v].lz);
    t[v].lz=0;
}

node pull(node l, node r){
    return {l.s+r.s, 0, l.sz+r.sz};
}

void build(int v, int tl, int tr){
    if(tl==tr)t[v]={a[tl], 0, 1};
    else{
        int tm=(tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v]=pull(t[v*2], t[v*2+1]);
    }
}

void update(int l, int r, ll x, int v, int tl, int tr){
    if(r<tl||tr<l)return;
    if(l<=tl&&tr<=r)apply(v, x);
    else{
        push(v);
        int tm=(tl+tr)/2;
        update(l, r, x, v*2, tl, tm);
        update(l, r, x, v*2+1, tm+1, tr);
        t[v]=pull(t[v*2], t[v*2+1]);
    }
}

node query(int l, int r, int v, int tl, int tr){
    if(r<tl||tr<l)return {0, 0, 0};
    if(l<=tl&&tr<=r)return t[v];
    push(v);
    int tm=(tl+tr)/2;
    return pull(query(l, r, v*2, tl, tm), query(l, r, v*2+1, tm+1, tr));
}
