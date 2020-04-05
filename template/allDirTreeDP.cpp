//全方位木DP
//引き算を定義できる場合（可換群）

vector<int> to[MAX_N];
 
struct DP {
  mint dp;
  int t;
  DP(mint dp=1, int t=0):dp(dp),t(t) {}
  DP& operator+=(const DP& a) {
    dp *= a.dp;
    dp *= comb(t+a.t, t);
    t += a.t;
    return *this;
  }
  DP operator-(const DP& a) const {
    DP res(*this);
    res.t -= a.t;
    res.dp /= comb(res.t+a.t, res.t);
    res.dp /= a.dp;
    return res;
  }
  DP addRoot() const {
    DP res(*this);
    res.t++;
    return res;
  }
};
 
DP dp[MAX_N];
 
void dfs(int v, int p=-1) {
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u,v);
    dp[v] += dp[u].addRoot();
  }
}
void bfs(int v, int p=-1) {
  for (int u : to[v]) {
    if (u == p) continue;
    DP d = dp[v] - dp[u].addRoot();
    dp[u] += d.addRoot();
    bfs(u,v);
  }
}
 
int main() {
  int n;
  cin >> n;
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs(0);
  bfs(0);
  rep(i,n) {
    cout << dp[i].addRoot().dp << endl;
  }
  return 0;
}

//引き算を定義できない場合（一般のモノイド）
vector<int> to[MAX_N];
 
struct DP {
  mint dp;
  int t;
  DP(mint dp=1, int t=0):dp(dp),t(t) {}
  DP operator+(const DP& a) const {
    return DP(dp*a.dp*comb(t+a.t, t), t+a.t);
  }
  DP addRoot() const {
    return DP(dp, t+1);
  }
};
 
vector<DP> dp[MAX_N];
DP ans[MAX_N];
 
DP dfs(int v, int p=-1) {
  DP dpSum;
  dp[v] = vector<DP>(to[v].size());
  rep(i,to[v].size()) {
    int u = to[v][i];
    if (u == p) continue;
    dp[v][i] = dfs(u,v);
    dpSum = dpSum + dp[v][i];
  }
  return dpSum.addRoot();
}
void bfs(int v, const DP& dpP=DP(), int p=-1) {
  int deg = to[v].size();
  rep(i,deg) if (to[v][i] == p) dp[v][i] = dpP;
 
  vector<DP> dpLeft(deg+1);
  rep(i,deg) dpLeft[i+1] = dpLeft[i] + dp[v][i];
  
  vector<DP> dpRight(deg+1);
  for (int i = deg-1; i >= 0; --i)
    dpRight[i] = dpRight[i+1] + dp[v][i];
  
  ans[v] = dpLeft[deg].addRoot();
 
  rep(i,deg) {
    int u = to[v][i];
    if (u == p) continue;
    DP d = dpLeft[i] + dpRight[i+1];
    bfs(u, d.addRoot(), v);
  }
}
 
int main() {
  int n;
  cin >> n;
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs(0);
  bfs(0);
  rep(i,n) cout << ans[i].dp << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
