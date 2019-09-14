#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  int i,n;
  double ans=0.0;//double型で宣言、初期化
  
  cin >> n;
  int a[n];
  for(i=0;i<n;++i)cin >> a[i];//入力を配列に格納

  for(i=0;i<n;i++)ans += (double)1/a[i];//逆数を足していく
  ans = 1.0/ans;//最後に逆数をとる

  printf("%.10f\n",ans);//小数点以下10桁まで出力
  return 0;
}
