#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){
    int n,aa;
    cin >> n;
    vector<int> a(n),b;
    rep(i,0,n-1){
        cin >> aa;
        a[i] = -aa;
    }

    b.push_back(a[0]);
    rep(i,1,n-1){
        auto it = upper_bound(b.begin(),b.end(),a[i]);
        int index = it - b.begin();
            if(it == b.end()){
            b.push_back(a[i]);
        }else{
            b[index] = a[i];
        }
    }

    cout << sz(b) << endl;
//  printf("%.10f\n",ans);

    return 0;
}