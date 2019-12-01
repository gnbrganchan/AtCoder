//ナップサック
// 入力
int n, W;
int weight[110], value[110];

// DPテーブル
int dp[110][10010];
// DP初期条件: dp[0][w] = 0
  for (int w = 0; w <= W; ++w) dp[0][w] = 0;

  // DPループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
      else dp[i+1][w] = dp[i][w];
    }
  }
  
  
//部分和数え上げ
// 入力
int n, A;
int a[110];

// DPテーブル
int dp[110][10010];

  memset(dp, 0, sizeof(dp));   // 一旦すべて 0 に
  dp[0][0] = 1;                // dp[0][0] だけ 1 に

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      (dp[i+1][j] += dp[i][j]) %= MOD;
      if (j >= a[i]) (dp[i+1][j] += dp[i][j-a[i]]) %= MOD;
    }
  }
