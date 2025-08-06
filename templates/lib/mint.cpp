#include <templates/init>

// const ll mod = 1e9+7;
const ll mod = 998244353;

template<int MOD> struct mint {
	int v; explicit operator int() const {return v;}
	mint():v(0) {}
	mint(ll _v) {v=int((-MOD<_v&&_v<MOD)?_v:_v%MOD);if(v<0)v+=MOD;}
	mint& operator+=(const mint& o) {if((v+=o.v)>=MOD)v-=MOD;return *this;}
	mint& operator-=(const mint& o) {if((v-=o.v)<0)v+=MOD;return *this;}
	mint& operator*=(const mint& o) {v=int((ll)v*o.v%MOD);return *this;}
	mint& operator/=(const mint& o) {return (*this)*=inv(o);}
	mint operator-() const {return mint(-v);}
	mint& operator++() {return *this+=1;}
	mint& operator--() {return *this-=1;}
	bool operator==(const mint& o) const {return v==o.v;}
	friend bool operator!=(const mint& a, const mint& b) {return !(a==b);}
	friend bool operator<(const mint& a, const mint& b) {return a.v<b.v;}
	friend mint operator+(mint a, const mint& b) {return a+=b;}
	friend mint operator-(mint a, const mint& b) {return a-=b;}
	friend mint operator*(mint a, const mint& b) {return a*=b;}
	friend mint operator/(mint a, const mint& b) {return a/=b;}
	friend mint exp(mint a, ll p) {mint ans=1;assert(p>=0);for(;p;p/=2,a*=a)if(p&1)ans*=a;return ans;}
	friend mint inv(const mint& a) {assert(a.v!=0);return exp(a,MOD-2);}
	friend istream& operator>>(istream& in, mint& a) {return in>>a.v;}
	friend ostream& operator<<(ostream& out, mint a) {return out<<a.v;}
};

typedef mint<mod> mi;
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

const int mx=1e6+5;
mi fac[mx], ifac[mx];
void init(){
    fac[0]=1;
    rep(i,1,mx)fac[i]=fac[i-1]*i;
    ifac[mx-1]=inv(fac[mx-1]);
    rev(i,mx-1)ifac[i]=ifac[i+1]*(i+1);
}
mi C(int n, int k) {
    if(n<0||k<0||k>n)return 0;
    return fac[n]*ifac[k]*ifac[n-k];
}
