
#include <bits/stdc++.h>
#define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
#define rep(i,n) drep(i,0,n-1)
#define drrep(i,cc,n) for(int i=(cc);i>=(n);--i)
#define rrep(i,n) drrep(i,0,n-1)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,v.size())if(i==0)cout << v[i];else cout << " " << v[i]; cout << endl;
#define arrprint(v,n) rep(i,n)if(i==0)cout << v[i];else cout << " " << v[i]; cout << endl;
#define matprint(v,n,m) rep(i,n){rep(j,m){cout << v[i][j] << " ";}cout << endl;}
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
using namespace std;
const int mod=1000000007;
const int INF=1001001001;
using ll = long long;
using P = pair<int,int>;
template<typename T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>; //小さいものから取り出す

const int TL = 1900;

int main(){
    auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
    random_device seed;
    mt19937 mt(seed());
    uniform_int_distribution<int> rnd1(0,25);

    while(true){
        auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
        auto dur = end - start;        // 要した時間を計算
        auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        if(msec>=TL) break;

    return 0;
}
