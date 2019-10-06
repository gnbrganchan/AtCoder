#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){

    string s;
    long long k,ans=0,st=1,en=1,n;
    int flg;
    cin >> s >> k;

    flg = 0;
    n = sz(s);
    if(s[0]==s[n-1]){
        rep(i,0,n-1){
            if(s[i]==s[i+1]){
                ++st;
            }
            else{
                break;
            }
        }
        drep(i,n-1,0){
            if(s[i]==s[i-1]){
                ++en;
            }
            else{
                break;
            }
        }
        if(st == n){
            cout << n*k/2 << endl;
            return 0;
        }
        rep(i,st,n-en-1){
            if(s[i] == s[i+1]){
                ans += k;
                s[i+1] = '1';
            }
        }
        ans += ((st+en)/2) * (k-1) + st/2 + en/2;
    }else{
        rep(i,0,n-1){
            if(s[i] == s[i+1]){
                ans += k;
                s[i+1] = '1';
            }
        }   
    }

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}