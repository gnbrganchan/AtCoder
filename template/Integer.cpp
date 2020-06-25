/*---fast pow---*/
ll mod_pow(ll x,ll n){
  ll res = 1;
  while(n > 0){
    if(n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}



//*---mint---*/
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
    drep(i,1,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].pow(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
} c(3e6);
//c.c(a,b)=>aCb mod



/*---最大公約数 from 20190929---*/
long long gcd(long long x, long long y) { return y ? gcd(y,x%y) : x;}


/*---最小公倍数 from 20191222---*/
long long lcm(long long x, long long y){return (x*y)/gcd(x,y);}


/*---素因数分解 from 20190929---*/
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



/*---桁数---*/
int keta(ll c) {
    int res = 0;
    while (c) {
      c /= 10;
      ++res;
    }
    return res;
}


/*---素数かどうかの判定---*/
bool isPrime(ll num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)if (num % i == 0) return false;

    return true;
}



/*---区間内の素数の個数 P113---*/
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//[a,b)の整数に対して篩を行う。is_prime[i-1] = true ⇔ iが素数
void segment_sieve(ll a, ll b){
  for(int i=0;(ll)i*i<b;i++) is_prime_small[i] = true;
  rep(i,b-a) is_prime[i] = true;
  
  for(int i = 2;(ll)i*i < b;i++){
    if(is_prime_small[i]){
      for(int j=2*i;(ll)j*j < b;j+=i)is_prime_small[j] = false; // [2,sqrt(b))の篩
      for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i)is_prime[j-a] = false; // [a,b)の篩
    }
  }
}



/*---Sieve 20200119 ---*/
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

//篩にかける
Sieve sieve(1e6);
//素因数分解(圧縮形式)
auto f = sieve.factor(a[i]);

