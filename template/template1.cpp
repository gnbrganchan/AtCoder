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
  int a,b,c,i,j,k,n,ans;
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;

  //unordered_map<string,int> mp;

  //priority_queue<int> pq; // default ‘å‚«‚¢‡
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst pq;

  cin >> a >> b;



  cout << ans << endl;

  return 0;

}
