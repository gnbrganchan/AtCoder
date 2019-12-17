//fast pow
ll mod_pow(ll x,ll n){
  ll res = 1;
  while(n > 0){
    if(n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

//mint
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint operator~() const { return mint(1) / *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint& operator/=(const mint& a){ (x*=a.pow(mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint pow(ll t) const {
    if(!t) return 1;
    mint res = pow(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint x, ll t) { return x.pow(t);}
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
struct comb {
  vm f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1) {
    f[0] = 1;
    rep(i,1,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].pow(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
} c(3e6);
//c.c(a,b)=>aCb

//最大公約数 from 20190929
long long gcd(long long x, long long y) { return y ? gcd(y,x%y) : x;}

//素因数分解 from 20190929
vector<pair<long long,int>> factorize(long long n) {
  vector<pair<long long,int>> res;
  for (long long i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    res.emplace_back(i,0);
    while (n%i == 0) {
      n /= i;
      res.back().second++;
    }
  }
  if (n != 1) res.emplace_back(n,1);
  return res;
}

//桁数
int keta(ll c) {
    int res = 0;
    while (c) {
      c /= 10;
      ++res;
    }
    return res;
}

