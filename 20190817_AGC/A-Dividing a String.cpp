#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>

using namespace std;
class CompareFirst
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first>n2.first; //>:?C?ö?@<:?~?ö
    }
};


int main(){

string s,prev,tmp;
int a,b,c,i,j,k,n,ans;
vector<string> lst;
vector<int> cnt;

//unordered_map<string,int> mp;

//priority_queue<int> pq; // default ea?á?‘?ö
//priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst pq;

cin >> s;

n = s.size();
ans = 0;

prev="";
tmp = "";
for(i=0;i<n;++i){
  if(prev == ""){
    prev = s[i];
    ++ans; 
  }else{
    tmp += s[i];
    if(prev == tmp){
    }else{
      ++ans;
      prev = tmp;
 //     cout << prev << endl;
      tmp = "";
    }
  }
}
if(prev != tmp && tmp != "")++ans;
cout << ans << endl;

return 0;

}