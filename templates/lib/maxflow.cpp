#include <templates/init>

const int mx=1005; // O(m^2 log C)
vi adj[mx];
ll c[mx][mx];
bool vis[mx];

bool dfs(int u, int e, ll t){
    vis[u]=1;
    if(u==e) return 1;
    for(int i:adj[u]){
        if(vis[i]||c[u][i]<t)continue;
        c[u][i]-=t; c[i][u]+=t;
        if(dfs(i, e, t)) return 1;
        c[u][i]+=t; c[i][u]-=t;
    }
    return 0;
}

ll maxflow(int n, int s, int e, ll thr=1e18){
    ll ans=0;
    while(thr){
        fill(vis, vis+n, 0);
        if(!dfs(s, e, thr)) thr/=2;
        else ans+=thr;
    }
    return ans;
}

void ae(int a, int b, ll w){ // directed edge
    adj[a].push_back(b);
    adj[b].push_back(a);
    c[a][b]+=w;
}
