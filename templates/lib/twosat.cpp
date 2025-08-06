#include <templates/init>

const int mx=5e5+5;
vi adj[mx], radj[mx], ord;
bool vis[mx], ans[mx];
int comp[mx];
void dfs(int u){
    vis[u]=1;
    for(int i:adj[u])if(!vis[i])dfs(i);
    ord.push_back(u);
}
void dfs2(int u, int cl){
    comp[u]=cl;
    for (int i:radj[u])if(!comp[i])dfs2(i, cl);
}
bool twosat(int n) {
    n*=2;
    rep(n)if(!vis[i])dfs(i);
    int cnt=1;
    rev(n)if(!comp[ord[i]])dfs2(ord[i],cnt++);
    rep(i,0,n,2){
        if(comp[i]==comp[i+1])return 0;
        ans[i/2]=comp[i]>comp[i+1];
    }
    return 1;
}
void ae(int a, bool na, int b, bool nb) {
    a=a*2^na^1; b=b*2^nb^1;
    adj[a^1].pb(b); radj[b].pb(a^1);
    adj[b^1].pb(a); radj[a].pb(b^1);
}
