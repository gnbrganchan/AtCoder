#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
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
  int i,j,k,l,n,m,Lsum=0,Lmax=0;
  long long ans = 1;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq;

  cin >> n;
  cin >> s;
  int a[2*n]={0};//0:L, 1:R
  
  rep(i,0,2*n-1){
    if(i%2==0){
      if(s[i]=='W')s[i]='B';
      else s[i]='W';
    }
    if(s[i]=='B'){
      if(Lsum<1){
        cout << 0 << endl;
        return 0;
      }
      ans *= Lsum;
      ans%=mod;
      --Lsum;
    }else{
      Lmax++;
      Lsum++;
    }
  }
  if(Lsum>0){
    cout << 0 << endl;
    return 0;
  }
  rep(i,1,Lmax){
    ans*=i;
    ans%=mod;
  }
  cout << ans << endl;

  return 0;

}