//深さ優先探索
void dfs(int v, int p){
  for(auto u : vec[v]){
    if(u == p)continue;
    //describe here. ans[u] += ans[v];
    dfs(u,v);
  }
}

//幅優先探索 from 20190929
vector<int> bfs(int sv) {
  vector<int> dist(n,INF), pre(n,-1);
  queue<int> q;
  dist[sv] = 0;
  q.push(sv);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : to[v]) {
      if (dist[u] != INF) continue;
      pre[u] = v;
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
 
  pair<int,int> best(INF,-1);
  rep(v,n) {
    if (v == sv) continue;
    for (int u : to[v]) {
      if (u == sv) {
        best = min(best, make_pair(dist[v],v));
      }
    }
  }
  if (best.first == INF) return vector<int>(n+1);
  int v = best.second;
  vector<int> res;
  while (v != -1) {
    res.push_back(v);
    v = pre[v];
  }
