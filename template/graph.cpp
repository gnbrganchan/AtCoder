struct edge{ int to,cost;}; //P92

/*---深さ優先探索 P33---*/
void dfs(int v, int p){
  for(auto u : vec[v]){
    if(u == p)continue;
    //describe here. ans[u] += ans[v];
    dfs(u,v);
  }
}



/*---幅優先探索 P36---*/
int h,w;
vector<string> s;
vector<vector<int>> d;
int dh[4] = {1,0,-1,0}, dw[4] = {0,1,0,-1};

//(sx, sy)からその他の点への最短経路を求める
int bfs(int sh, int sw){
    queue<P> que;
    rep(i,0,h-1)rep(j,0,w-1)d[i][j] = INF;
    que.push(P(sh,sw));
    d[sh][sw] = 0;
    while(!que.empty()){
        P p = que.front();que.pop();
        rep(i,0,3){
            //移動した後の点を(nx, ny)とする
            int nh = p.first + dh[i], nw = p.second + dw[i];

            //移動が可能かの判定とすでに訪れたことがあるかの判定
            //d[nx][ny]==INFなら未探索
            if(0<=nh && nh<h && 0<=nw && nw<w && s[nh][nw]!='#' && d[nh][nw]==INF){
                que.push(P(nh,nw));
                d[nh][nw]=d[p.first][p.second] + 1;
            }
        }
    }
    return 0;
}



/*---単一始点最短路問題（ベルマンフォード法） P95---*/
//頂点fromから頂点toへのコストcostの辺
struct edge{int from, to, cost;};

edge es[MAX_E];  //辺

int d[MAX_V];  //最短距離
int V, E;  //Vは頂点数、Eは辺数

//s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s){
  rep(i, 0, V-1)d[i] = INF;
  d[s] = 0;
  while(true){
    bool update = false;
    rep(i, 0, E-1){
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if(!update)break;
  }
}

//trueなら負閉路が存在する
bool find_negative_loop(){
  memset(d, 0, sizeof(d));
  
  rep(i, 0, V-1){
    rep(j, 0, E-1){
      edge e = es[j];
      if(d[e.to] >  d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        
        //n回目にも更新があるなら負の閉路が存在する
        if(i == V-1)return true;
      }
    }
  }
  return false;
}



/*---単一始点最短路問題（ダイクストラ法）※低速O(V^2)---*/
int cost[MAX_V][MAX_V]; //辺のコスト
int d[MAX_V];  //頂点sからの最短距離
bool used[MAX_V]; //すでに使われたかのフラグ
int V; //頂点数

//始点sから各頂点への最短距離を求める
void dijkstra(int s){
  fill(d, d+V, INF);
  fill(used, used+V, false);
  d[s] = 0;
  
  while(true){
    int v = -1;
    //まだ使われていない頂点のうち距離が最小のものを探す
    rep(u, 0, V-1){
      if(!used[u] && (v == -1 || d[u] < d[v]))v = u;
    }
    if(v == -1)break;
    used[v] = true;
    
    rep(u, 0, V-1){
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }
}
  


/*---単一始点最短路問題（ダイクストラ法）※高速O(ElogV)---*/
struct edge{int to, cost;};

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
  //greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d+V, INF);
  d[s] = 0;
  que.push(P(0,s));
  
  while(!que.empty()){
    P p = que.top();que.pop();
    int v = p.second;
    if(d[v] < p.first)continue;
    rep(i, 0, G[v].size()-1){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}



/*---全点対最短路問題（ワーシャルフロイド法）P98---*/
int d[MAX_V][MAX_V];  //d[u][v]は辺e=(u,v)のコスト（存在しない場合はINF、ただしd[i][i]=0)
int V; //頂点数

void warshall_floyd(){
  rep(k, 0, V-1)rep(i, 0, V-1)rep(j, 0, V-1)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}



/*---Union-Find木 P84---*/
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



/*---最大流 Ford Fulkerson P190---*/
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
      }int 
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



/*---最小費用流 P200---*/
//辺を表す構造体（行先、容量、コスト、逆辺）
struct edge{int to,cap, cost, rev;};

int V; //頂点数
vector<edge> G[MAX_V]; //グラフの隣接リスト表現
int dist[MAX_V]; //最短距離
int prevv[MAX_V], preve[MAX_V]; //直前の頂点と辺

//fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する
void add_edge(int from, int to, int cap, int cost){
  G[from].push_back((edge){to, cap, cost, G[to].size()});
  G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

//sからtへの流量fの最小費用流を求める
//流せない場合は-1を返す
int min_cost_flow(int s, int t, int f){
  int res = 0;
  while(f > 0){
    //ベルマンフォード法により、s-t間最短路を求める
    fill(dist, dist+V,INF);
    dist[s] = 0;
    bool update = true;
    while(update){
      update = false;
      rep(v,0,V-1){
        if(dist[v] == INF) continue;
        rep(i,0,G[v].size()-1){
          edge &e = G[v][i];
          if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            update = true;

          }
        }
      }
    }
    if(dist[t] == INF){
      //これ以上流せない
      return -1;
    }
    //s-t間最短路に沿ってめいっぱい流す
    int d = f;
    for(int v=t;v!=s;v=prevv[v]){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * dist[t];
    for(int v=t;v!=s;v=prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}


/*---二部グラフの最大マッチングP197---*/
int V; //頂点数
vector<int> G[MAX_V]; //グラフの隣接リスト表現
int match[MAX_V]; //マッチングのペア
bool used[MAX_V]; //DFSですでに調べたかのフラグ

//uとvを結ぶ辺をグラフにする
void add_edge(int u, int v){
  G[u].push_back(v);
  G[v].push_back(u);
}

//増加パスをDFSで探す
bool dfs(int v){
  used[v] = true;
  rep(i,0,G[v].size()-1){
    int u = G[v][i], w = match[u];
    if(w < 0 || !used[w] && dfs(w)){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}



/*---二部グラフの最大マッチングを求める---*/
int bipartite_matching(){
  int res = 0;
  memset(match, -1, sizeof(match));
  rep(v,0,V-1){
    if(match[v] < 0){
      memset(used, 0, sizeof(used));
      if(dfs(v)){
        res++;
      }
    }
  }
  return res;
}
