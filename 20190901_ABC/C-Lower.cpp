#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
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
  string s,t,ss;
  int a,b,i,j,k,l,n,ans=0,m=0;
  vector<string> vs;
  vector<int> v[26];
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default ea?á?‘?ö
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq

  cin >> n;

  cin >> b;
  rep(i,0,n-2){
    cin >> a;
    if(b >= a){
      m++;
    }else{
      m = 0;
    }
    b = a;
    if(ans < m)ans = m;
  }

 
  cout << ans << endl;
  return 0;

}
