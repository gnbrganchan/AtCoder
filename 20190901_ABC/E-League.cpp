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
  int i,j,k,l,n,m,ans=0;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq;

  cin >> n;
  int a[n][n-1];
  int shouka[n] = {0},nshouka[n] = {0};
  int nokori=0.5*n*(n-1);
  int aite;
  int flg = 0;
  
  rep(i,0,n-1){
    rep(j,0,n-2)cin >> a[i][j];
  }
  while(nokori){
    rep(i,0,n-1){
      if(shouka[i] == n-1)continue;
      if(nshouka[i] == 1)continue;
      aite = a[i][shouka[i]];
    //  rep(j,0,n-2)cout << shouka[j] << endl;
      --aite;
      if(a[aite][shouka[aite]] == (i+1)){
        --nokori;nshouka[i]=1;nshouka[aite]=1;flg=1;
      }
    }
    if(flg == 0){
      cout << -1 << endl;
      return 0;
    }
  //  rep(i,0,n-1)cout << nshouka[i] <<  " ";
  //  cout << endl;
    rep(i,0,n-1){
      shouka[i]+=nshouka[i];
      nshouka[i] = 0;
    }
   // rep(i,0,n-1)cout << shouka[i] <<  " ";
   // cout << endl;
   // cout << nokori << endl;
    ++ans;flg = 0;
    
  }/*
    rep(i,0,n-1){
    rep(j,0,n-2)cout << a[i][j] << " ";
      cout << endl;
  }*/
  
  cout << ans << endl;

 
  return 0;
}
