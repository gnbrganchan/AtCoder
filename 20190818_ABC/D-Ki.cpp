#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<unordered_map>
#include<queue>
#define rep(i,n) for(i=0;i<n;++i)
 
using namespace std;
 
vector<int> vec[200005];
vector<int> ans;
 
class CompareFirst
{
public:
  bool operator()(pair<int,int> n1,pair<int,int> n2) {
    return n1.first>n2.first; //>:desc <:asc
  }
};
void dfs(int v, int p){
  for(auto u : vec[v]){
    if(u == p)continue;
    ans[u] += ans[v];
    dfs(u,v);
  }
}
 
 
int main(){
 
  string s;
  int a,b,c,i,j,k,n,q,p,x;
 
  cin >> n >> q;
  ans.resize(n);
  rep(i,n-1){
    cin >> a >> b;
    --a;--b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  rep(i,q){
    cin >> p >> x;
    --p;
    ans[p] += x;
  }
  dfs(0,-1);
 
  rep(i,n)cout << ans[i] << endl;
 
  return 0;
 
}