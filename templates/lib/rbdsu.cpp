#include <templates/init>

const int mx=2e5+5;
int lnk[mx], sz[mx];
stack<int> hist;
void init(){
    rep(i,0,mx) lnk[i]=i, sz[i]=1;
    while(sz(hist)) hist.pop();
}
int find(int x){
    return x==lnk[x]?x:find(lnk[x]);
}
bool unite(int a, int b){
    a=find(a);b=find(b);
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a, b);
    lnk[b]=a; sz[a]+=sz[b];
    hist.push(b);
    return 1;
}
void rollback(int t){
    while(sz(hist)>t){
        int x=hist.top(); hist.pop();
        sz[lnk[x]]-=sz[x];
        lnk[x]=x;
    }
}
