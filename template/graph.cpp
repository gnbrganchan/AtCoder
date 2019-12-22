struct edge( int to,cost;}; //P92

//深さ優先探索 P33
void dfs(int v, int p){
  for(auto u : vec[v]){
    if(u == p)continue;
    //describe here. ans[u] += ans[v];
    dfs(u,v);
  }
}

//幅優先探索 from 20190929 P36
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
}
  
//Union-Find木 P84
int par[MAX_N];  //親
int rank[MAX_N] //木の深さ
//初期化
void init(int n){
  rep(i,0,n-1){
    par[i] = i;
    rank[i] = 0;
  }
}
//木の根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}
//xとyの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  
  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}
//xとyが同じ集合に属するか否か
bool same(int x, int y){
  return find(x) == find(y);
}

//最大流 Ford Fulkerson P190
//辺を表す構造体（行先、容量、逆辺）
struct edge {int to,cap, rev;};

vector<edge> G[MAX_V];//グラフの隣接リスト表現
bool used[MSX_V];//dfsですでに調べたかのフラグ

//from からtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size()-1});
}
  
//増加パスをdfsで探す
int dfs(int v, int t, int f){
  if(v == t) return f;
  used[v] = true;
  rep(i,0,G[v].size()-1){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to,t,min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
//sからtへの最大流を求める
int max_flow(int s, int t){
  int flow = 0;
  while(true){
    memset(used, 0, sizeof(used));
    int f = dfs(s,t,INF);
    if(f == 0) return flow;
    flow += f;
  }
}
      
