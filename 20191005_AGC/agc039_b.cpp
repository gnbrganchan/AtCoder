#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

vector<int> to[205];
vector<int> dist;
int n;

int bfs(int i){
    queue<int> q;
    vector<int> pre(n,-1);
    int ans = -1;
    dist[i] = 1;
    q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int u: to[v]){
 //           cout << v << endl;
            //rep(i,0,n-1)cout << dist[i] << " ";
 //           for(int uu : to[v])cout << uu << " ";
 //           cout << endl;
            if(dist[u] != -1){
                if(dist[u] != dist[v]+1 && dist[u] != dist[v] -1){
                    return -1;
                }
                continue;
            }
            pre[u] = v;
            dist[u] = dist[v]+1;
            q.push(u);
        }
    }
    rep(i,0,n-1) ans = max(ans,dist[i]);
    return ans;

}

int main(){
    int cls_num,ans=-1;
    string s;
    cin >> n;
    dist.resize(n);
//    int s[n][n];
    rep(i,0,n-1){
        cin >> s;
        rep(j,0,n-1){
            if(s[j] == '1'){
                to[j].push_back(i);
            }
        }
    }
    rep(i,0,n-1){
      //  int i = 0;
        rep(j,0,n-1)dist[j] = -1;
        cls_num = bfs(i);
        ans = max(ans,cls_num);
    }

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}