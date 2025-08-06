#include <templates/init>

// calculates sum(i, 0, n+1) of (a*i+b)//c
ll floor_sum(ll a, ll b, ll c, ll n){
    if(!a)return b/c*(n+1);
    if(a>=c||b>=c) return (n*(n+1)/2)*(a/c)+(n+1)*(b/c)+floor_sum(a%c,b%c,c,n);
    return (a*n+b)/c*n-floor_sum(c,c-b-1,a,(a*n+b)/c-1);
}
