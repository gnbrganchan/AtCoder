#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define vecprint(v) rep(i,0,v.size()-1)cout << v[i] << " ";cout << endl;
#define mod 1000000007
using namespace std;

int main(){

  int n,ans;
 
  cin >> n;
  int a[n];
  int max=0,smax=-1;
  rep(i,0,n-1){
    cin >> a[i];
    if(max <= a[i]){
      smax = max;
      max = a[i];
    }else if(smax < a[i]){
      smax = a[i];
    }
  }
  
  rep(i,0,n-1){
    if(a[i] == max)cout << smax << endl;
    else   cout << max << endl;
  }

    return 0;
}