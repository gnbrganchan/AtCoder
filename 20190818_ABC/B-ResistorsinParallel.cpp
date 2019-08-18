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
  ans1 = 0;
  int a[n];
  for(i=0;i<n;++i){
    cin >> a[i];
  }

  tmp = 0.0;
  for(i=0;i<n;i++)tmp += (double)1/a[i];
  ans = (double)1.0/tmp;

printf("%.10f\n",ans);
  return 0;
 
}