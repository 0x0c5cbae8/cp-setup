#include <templates/init>

const int mx=2e5+5;
int lnk[mx], sz[mx];
void init(){
    rep(i,0,mx) lnk[i]=i, sz[i]=1;
}
int find(int x){
    return x==lnk[x]?x:lnk[x]=find(lnk[x]);
}
bool unite(int a, int b){
    a=find(a);b=find(b);
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a, b);
    lnk[b]=a; sz[a]+=sz[b];
    return 1;
}
