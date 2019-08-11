#include<iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){

int i,k,x,ans;

cin >> k >> x;

for(i=0;i<(2*k-1);i++){
  if( i != 0) cout << " ";
  cout << x + i - (k-1);
}

cout << endl;

return 0;

}