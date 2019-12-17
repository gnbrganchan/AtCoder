typedef vector<int> vec;
typedef vector<vec> mat;

//A*B
mat mul(mat &A, mat &B){
  mat C(A.size(),vec(B[0].size()));
  rep(i,0,A.size()-1){
    rep(k,0,B.size()-1){
      rep(j,0,B[0].size()-1){
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return C;
}

//A^n
mat pow(mat A, ll n){
  mat B(A.size(),vec(A.size()));
  rep(i,0,A.size()-1){
    B[i][i] = 1;
  }
  while(n > 0){
    if(n & 1) B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}
