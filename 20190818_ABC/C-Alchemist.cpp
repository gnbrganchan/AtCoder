#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<unordered_map>
#include<queue>
 
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
  int b,c,i,j,k,n;
  long long  ans1;
  double ans,tmp;
  vector<string> lst;
  vector<int> cnt;
 
  //unordered_map<string,int> mp;
 
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst pq;
 
  cin >> n;
  ans = 0;
  vector<int> a(n);
  for(i=0;i<n;++i){
    cin >> a[i];
  }
 
  sort(a.begin(),a.end());
  ans = (double)a[0];
  for(i=1;i<n;i++){
    ans = (ans + a[i])/2;
  }

printf("%.10f\n",ans);
  return 0;
 
}