#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first>n2.first;
    }
};

int main(){

string s;
int a,b,c,i,j,k,n,m,ans=0,max,index;
vector<string> lst;
vector<int> cnt;

unordered_map<string,int> mp;

priority_queue<int> maxpq; // default ‘å‚«‚¢‡
priority_queue<pair<int,int>,vector<pair<int,int>>,CompareDist> pq;

cin >> n >> m;

vector<pair<int,int>> pairs(n);
int flg_delete[n]={0};

for(i=0;i<n;i++){
  cin >> a >> b;
  pq.push(make_pair(a,b));
}


for(i=1;i<=m;i++){
  while(pq.top().first == i && !pq.empty()){
    maxpq.push(pq.top().second);
    pq.pop();
  }

  if(!maxpq.empty()){
    ans += maxpq.top();
    maxpq.pop();
  }
}

cout << ans << endl;

return 0;

}