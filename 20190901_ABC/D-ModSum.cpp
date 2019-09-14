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
  int a,b,i,j,l,m=0;
  unsigned long long n,k,ans;
  vector<string> vs;
  vector<int> v[26];
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq

  cin >> n;
  n--;
 // k = 0.5*n;
  if(n%2==0){
    k=n/2;
    ans = k*(n+1);
  }else{
    k=(n+1)/2;
    ans = n*k;
  }
 // ans = 0.5*n*(n+1);
  
 
  cout << ans << endl;
  return 0;

}
