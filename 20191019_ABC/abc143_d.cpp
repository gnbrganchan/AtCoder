#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){
    int a,b,n,lower,upper,ans=0;
    cin >> n;
    vector<int> l(n);
    rep(i,0,n-1)cin >> l[i];

    sort(l.begin(),l.end());

    rep(i,0,n-1){
        rep(j,i,n-1){
            a = l[i];
            b = l[j];
            if(i<j){
                lower = b-a;
                upper = a+b;
              //  auto li = upper_bound(l.begin(),l.end(),lower);
                auto ui = lower_bound(l.begin(),l.end(),upper);
               // if(a+b==)
               
                if((ui-l.begin()-1)<=j)continue;
               // cout << i <<" "<<j<<" "<<ui-l.begin() << " " <<ui-l.begin()-j<<endl;
                ans += ui - l.begin() -j-1;
                //if(ui==l.end())--ans;
            }
        }
    }

    cout << ans << endl;
//  printf("%.10f\n",ans);

    return 0;
}