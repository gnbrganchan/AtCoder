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
        return n1.first>n2.first; //>:¸‡@<:~‡
    }
};


int main(){

string s;
int a,b,c,i,j,k,n,ans;
vector<string> lst;
vector<int> cnt;

//unordered_map<string,int> mp;

//priority_queue<int> pq; // default ‘å‚«‚¢‡
//priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst pq;

cin >> a >> b;



cout << ans << endl;

return 0;

}