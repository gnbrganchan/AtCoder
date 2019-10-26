#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

vector<int> a;

void rev(int i){
    i++;
    for(int j=1;j*j<=i;++j){
        if(i % j == 0){
            a[j-1] = a[j-1] == 1 ? 0 : 1;
            if(j*j!=i)a[(i/j)-1] = a[(i/j)-1] == 1 ? 0 : 1;
        }
    }
}


int main(){
    int n,m=0;
    cin >> n;
    a.resize(n);
    vector<int> b;
    rep(i,0,n-1)cin >> a[i];

    drep(i,n-1,0){
        if(a[i]==1){
            rev(i);
            ++m;
            b.push_back(i+1);
        }
        // rep(j,0,n-1){
        //     cout << a[j] << " ";
        // }
        // cout << i << endl;
    }
    if(m==0){
        cout << 0 << endl;
    }else{
        cout << m << endl;
        rep(i,0,m-1){
            cout << b[i] << endl;
        }
    }
    return 0;
}