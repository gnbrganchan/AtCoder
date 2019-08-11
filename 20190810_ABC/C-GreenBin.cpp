#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){

int flg;
long i,j,n,ans=0,len;
string s[100000];
vector<string> lst;
vector<int> count;
unordered_map<string,int> mp;


cin >> n;

for(i=0;i<n;i++){
  cin >> s[i];
  sort(s[i].begin(),s[i].end());
  ans += mp[s[i]];
  mp[s[i]]++;
}

cout << ans << endl;

return 0;

}