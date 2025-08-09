#include <templates/init>

const int mx=2e5+5, ms=18;
vi adj[mx];
int dep[mx], up[mx][ms];

void dfs(int u, int e){
    up[u][0]=e;
    rep(i,1,ms) up[u][i]=up[up[u][i-1]][i-1];
    for(int i:adj[u]){
        if(i==e) continue;
        dep[i]=dep[u]+1;
        dfs(i,u);
    }
}

int jmp(int u, int d){
    rep(ms)if(d&(1<<i)) u=up[u][i];
    return u;
}

int lca(int u, int v){
    if(dep[u]<dep[v]) swap(u,v);
    u=jmp(u, dep[u]-dep[v]);
    if(u==v) return u;
    rev(ms) {
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

int dist(int u, int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
