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
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq

  cin >> a >> b;
  int kuchi = 1;

  //else if(b%(a-1) == 0)ans = b/(a-1);
  //else ans = (b/(a-1)) + 1;
  while(1){
    if(kuchi >= b)break;
    kuchi--;
    kuchi += a;
    ans++;
  }
  if(b == 1)ans = 0;
  cout << ans << endl;
  return 0;

}
