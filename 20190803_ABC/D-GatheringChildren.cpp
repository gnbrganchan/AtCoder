#include<iostream>
using namespace std;
int main(){
string s;
char bloc1,bloc2,dir;
int num_f,num_s,rnum,lnum,lcount,i,count,len;
cin >> s;
len = (int)(s.length());
if(len == 2)cout << 1 << " " << 1;
  else{
bloc1 = s[0];
bloc2 = s[1];
  
num_f = 0;
num_s = 0;
rnum = 0;
lnum = 0;
lcount = 0;
dir = 'f';
for(count=0;count<(len-1);count++){
  if(bloc1 == 'R' && bloc2 == 'L'){
    if(dir = 's'){
      rnum = num_s+1;
      lnum = num_f+1;
    }else{
      rnum = num_f+1;
      lnum = num_s+1;
    }
    dir = 'f';
    num_f = 0;
    num_s = 0;
  }
  if(bloc1 == 'L' && bloc2 == 'L'){
    if(dir == 'f'){
      rnum++;
      dir = 's';
    }else{
      lnum++;
      dir = 'f';
    }
    lcount++;
  }
  if(bloc1 == 'L' && bloc2 == 'R'){
    cout << rnum << " " << lnum << " ";
    if(lcount > 0){
      for(i=0;i<lcount;i++)cout << 0 << " ";
    }
    lcount = 0;
    dir = 'f';
  }
    if(bloc1 == 'R' && bloc2 == 'R'){
      if(dir == 'f'){
        num_f++;
        dir = 's';
      }else{
        num_s++;
        dir = 'f';
      }
      cout << 0 << " ";
    }
  bloc1 = bloc2;
  bloc2 = s[(count+2)];
}
    cout << rnum << " " << lnum << " ";
    if(lcount > 0){
      for(i=0;i<(lcount-1);i++)cout << 0 << " ";
        cout << 0;
    }
 
      
  }
return 0;
}