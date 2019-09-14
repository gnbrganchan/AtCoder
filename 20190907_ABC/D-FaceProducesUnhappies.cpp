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
  int i,j,l,n,m;
  long long k;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq;

  cin >> n >> k;
  cin >> s;
  long long ans = 0;
  long long lr = 0;
  long long rl = 0;
  
  rep(i,1,n-1){
    
    if(s[i] == s[i-1])++ans;
    if(k == 0)continue;
    if(s[i-1] == 'L' && s[i] == 'R'){
      if(rl > 0){
        ans += 2;
        --rl;
        --k;
      }else{
      ++lr;
        }
    }
    
    if(s[i-1] == 'R' && s[i] == 'L'){
      if(lr > 0){
        ans += 2;
        --lr;
        --k;
      }else{
      ++rl;
        }
    }
    if(i == n-1 && s[i] == 'R'){
      if(lr > 0){
        ans += 1;
        --lr;
        --k;
      }else{
      ++rl;
        }
    }
    if(i == n-1 && s[i] == 'L'){
      if(rl > 0){
        ans += 1;
        --rl;
        --k;
      }else{
      ++lr;
        }
    }
  }
//  ans += max(lr + rl,k);
  
  cout << ans << endl;
//  printf("%.10f\n",ans);

  return 0;

}
