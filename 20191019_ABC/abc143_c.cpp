#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){
    int n,ans=1;
    string s;
    cin >> n  >> s;

    rep(i,1,n-1){
        if(s[i]!=s[i-1])++ans;
    }

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}