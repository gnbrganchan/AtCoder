#include<vector>
#include<unordered_map>
#include<queue>
#define rep(i,n) for(i=0;i<n;++i)
#define cons 1000000007
typedef long long ll;
int mod = 1000000007;
 
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    (x += a.x) %= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    (x += mod-a.x) %= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
using namespace std;
class CompareFirst
{
public:
  bool operator()(pair<int,int> n1,pair<int,int> n2) {
    return n1.first>n2.first; //>:desc <:asc
  }
};
 
 
int main(){
 
  string s;
  long long i,j,n,k;
  long long tmp;
  long long ans;
 
  vector<string> vs;
  vector<int> vi;
  pair<int,int> pr;
 
  //unordered_map<string,int> mp;
 
  //priority_queue<int> pq; // default ea?á?‘?ö
  //priority_queue<pair<int,int>,vector<pair<int,int>>,CompareFirst pq;
 
  cin >> n >> k;
  long long a[n];
  long long ai[2001]={0};
  long long kk = (long long)(k*(k-1)/2) % cons;
  ans = 0;
  rep(i,n){
    cin >> a[i];
    ++ai[a[i]];
  }
 // rep(i,n)cout << a[i] << endl;
  tmp = 0;
  for(i=1;i<=2000;++i){
    tmp += ai[i-1] % cons;
    tmp = tmp % cons;
    
    ans += (long long)(ai[i]*tmp*kk) % cons;
    ans = ans % cons;
  }
  for(i=0;i<(n-1);++i){
    for(j=(i+1);j<n;j++){
      if(a[i] > a[j]){
        ans += k;
        ans = ans % cons;
      }
    }
  }
 
  cout << ans  << endl;
 
  return 0;
 
}