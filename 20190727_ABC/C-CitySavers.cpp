#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
 
using namespace std;
class CompareFirst
{
public:
  bool operator()(pair<int,int> n1,pair<int,int> n2) {
    return n1.first>n2.first; //>:desc <:asc
  }
};
 
 
int main(){
 
  string s;
  int i,j,k,l,n,m;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default ea?á?‘?ö
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq;
 
  cin >> n;
  
  long a[n+1],b[n],ans=0.0;
  
  rep(i,0,n)cin >> a[i]; 
  rep(i,0,n-1)cin >> b[i];
  
  rep(i,0,n-1){
    if(b[i]==0)continue;
    if(b[i] <= a[i]){
      ans += b[i];
      continue;
    }
    if(b[i] <= a[i] + a[i+1]){
      ans += b[i];
      b[i] -= a[i];
      a[i+1] -= b[i];
      continue;
    }
    ans += a[i]+a[i+1];
    a[i+1]=0;
  }
 
  cout << ans << endl;
 
  return 0;
 
}