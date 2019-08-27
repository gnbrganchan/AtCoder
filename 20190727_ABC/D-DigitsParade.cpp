#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
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
  char dig;
  int i,j,k,l,n,m,keta;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq;
  
  long long ans=0,com;

  cin >> s;
  n = (int)(s.size());
  long long dp[13]={0};

  int mul = 1;
  dp[0]=1;
  rep(i,0,n-1){
      long long nextdp[13]={0};
    dig = s[n-1-i];
    if(dig == '?'){
      rep(j,0,9){
        rep(k,0,12){
          nextdp[(mul*j+k)%13] += dp[k];
          nextdp[(mul*j+k)%13] %= mod;
        }
      }
      j=-1;
    }else{
      j=(int)(dig - '0'); 
      rep(k,0,12){
        nextdp[(mul*j+k)%13] += dp[k];
        nextdp[(mul*j+k)%13] %= mod;
      }
    }
    mul *= 10;
    mul %= 13;
    swap(dp,nextdp);
 //   cout << i << " ";
 //   cout << j << " ";
 //   cout << dig << " ";
 //   rep(j,0,12)cout << dp[j] << " ";
 //     cout << endl;
  }

  cout << dp[5] << endl;

  return 0;

}