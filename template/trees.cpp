void dfs(int v, int p){
  for(auto u : vec[v]){
    if(u == p)continue;
    ans[u] += ans[v];
    dfs(u,v);
  }
}