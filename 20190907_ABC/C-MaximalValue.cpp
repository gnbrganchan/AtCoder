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
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq;

  cin >> n;
  int b[n-1];
  rep(i,0,n-2)cin >> b[i];
  
  long long ans = b[0];
  rep(i,1,n-2){
  ans += min(b[i-1],b[i]);
  }
  ans += b[n-2];
  
  cout << ans << endl;
//  printf("%.10f\n",ans);

  return 0;

}
