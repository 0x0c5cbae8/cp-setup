#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
#define cut4(a,b,c,d,e,...) e
#define rep1(n) for(int i=0;i<(n);++i)
#define rep2(i,n) for(int i=0;i<(n);++i)
#define rep3(i,a,b) for(int i=(a);i<(b);++i)
#define rep4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define rev1(n) for(int i=(n)-1;i>=0;--i)
#define rev2(i,n) for(int i=(n)-1;i>=0;--i)
#define rev3(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define rev4(i,a,b,c) for(int i=(a)-1;i>=(b);i-=(c))
#define rep(...) cut4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rev(...) cut4(__VA_ARGS__,rev4,rev3,rev2,rev1)(__VA_ARGS__)
#define each(a, x) for(auto& a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define over(x) {cout<<(x)<<'\n';return;}
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double db;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
ll rng() { return uniform_int_distribution<ll>(0, INT64_MAX)(gen); }
// const db PI = atan(1)*4;
// const ll mod = 1e9+7;
const ll mod = 998244353;

void solve(int){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc=1;
    // cin>>tc;
    rep(tc) solve(i);
    return 0;
}
