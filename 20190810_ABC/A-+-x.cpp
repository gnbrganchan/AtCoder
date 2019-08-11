#include<iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){

int a,b,c,ans;

cin >> a >> b;

ans = max({a+b,a-b,a*b});

cout << ans << endl;

return 0;

}