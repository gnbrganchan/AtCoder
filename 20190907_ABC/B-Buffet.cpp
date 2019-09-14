#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define mod 1000000007

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
  int a[n],b[n],c[n];
  
  rep(i,0,n-1){
    cin >> a[i];
    --a[i];
  }
  rep(i,0,n-1){
    cin >> b[i];
  }
  rep(i,0,n-2){
    cin >> c[i];
  }
  
  int ans = 0;
  int prev = 999;
  rep(i,0,n-1){
    ans += b[a[i]];
    if(prev == a[i]-1)ans += c[a[i]-1];
    prev = a[i];
//    cout <<a[i] << " " << b[a[i]] <<" " << ans << endl;
  }
    
  

  cout << ans << endl;
//  printf("%.10f\n",ans);

  return 0;

}
