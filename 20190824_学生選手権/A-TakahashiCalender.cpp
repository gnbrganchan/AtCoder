#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<unordered_map>
#include<queue>
#define rep(i,n) for(i=0;i<n;++i)
 
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
  int a,b,c,i,j,k,n,ans,m,d,d1,d10;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
 
  //unordered_map<string,int> mp;
 
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst pq;
 
  cin >> m >> d;
  ans = 0;
  for(i=1;i<=m;++i){
    for(j=10;j<=d;++j){
      
      d1 = j % 10;
      d10 = j/10;
      if(d1*d10 == i && d1 > 1 && d10 > 1){
        ++ans;
     //   cout << i << " " << j << " " << d1 << " "<< d10 << endl;
      }
    }
  }
 
  cout << ans << endl;
 
  return 0;
 
}