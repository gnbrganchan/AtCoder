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
