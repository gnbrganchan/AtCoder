#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){
    int n;

    cin >> n;

    int a,ans[n];

    rep(i,0,n-1){
        cin >> a;
        ans[a-1]=i+1;
    }

    rep(i,0,n-1)cout << ans[i] << endl;
//  printf("%.10f\n",ans);

    return 0;
}