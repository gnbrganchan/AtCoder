#include<iostream>
using namespace std;
int main(){
int N, H1, H2, H3,i,flg,max,min;
cin >> N;
if(N ==1) cout << "Yes" << endl;
if(N==2){
  cin >> H1 >> H2;
  if((H1 - H2) <= 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
if(N > 2){
  cin >> H1;
  if(H1 > 0) H1--;
  flg = 0;
  for(i=0;i<(N-1);i++){
    cin >> H2;
    if(H1 > H2) flg = 1;
    if((H2 - H1) > 0) H2--;
    H1 = H2;
  }
  if(flg == 0) cout << "Yes" << endl;
  if(flg == 1) cout << "No" << endl;
}
return 0;
}