#include<iostream>
using namespace std;
int main(){
int N, p,ans;
cin >> N;
if(N < 10) p = 1;
else if(N < 100) p = 2;
else if(N<1000) p = 3;
else if(N < 10000) p = 4;
else if(N < 100000) p = 5;
else p = 6;
 
if(p == 1) ans = N;
if(p == 2) ans = 9;
if(p == 3) ans = 9+N-99;
if(p == 4) ans = 909;
if(p == 5) ans = 909 + N - 9999;
if(p == 6) ans = 90909;
  
cout << ans << endl;
return 0;
}