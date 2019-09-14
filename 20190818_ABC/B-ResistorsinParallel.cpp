#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  int i,n;
  double ans=0.0;
  
  cin >> n;
  int a[n];
  for(i=0;i<n;++i)cin >> a[i];

  for(i=0;i<n;i++)ans += (double)1/a[i];
  ans = 1.0/ans;

  printf("%.10f\n",ans);
  return 0;
}
