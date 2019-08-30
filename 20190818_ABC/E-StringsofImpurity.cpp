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



  string s,t,ss;
  int i,j,k,l,n,m;
  vector<string> vs;
  vector<int> v[26];
  pair<int,int> pr;
  //unordered_map<string,int> mp;
  //priority_queue<int> pq; // default Åea?Å·?Åë?Åˆ
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst> pq

  cin >> s;
  cin >> t;
  
  long ans = 0;
  long pos = 0;
 
  ss = s+s;
  rep(i,0,(int)(ss.size())-1){
    n = (int)(ss[i] - 'a');
    v[n].push_back(i+1);
  }
  rep(i,0,(int)(t.size())-1){
    n = (int)(t[i] - 'a');
    if(v[n].empty()){
     cout << -1 << endl;
      return 0;
    }
    pos = *lower_bound(v[n].begin(),v[n].end(),pos+1);
  //  rep(j,0,v[n].size()-1){
  //    if(v[n][j] > pos){
    //    pos = v[n][j];
      //  break;
     // }
   // }
    if(pos > (int)(s.size())){
      ans += (int)(s.size());
      pos -= (int)(s.size());
    }
  }
  ans += pos;
  
  cout << ans << endl;

  return 0;

}