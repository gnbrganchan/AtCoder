#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){
    int n,d,ans;
    cin >> n >> d;

    if(n % (2*d+1) == 0)ans = n / (2*d+1);
    else ans = (n / (2*d+1)) + 1;
    
    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}