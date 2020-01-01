typedef vector<int> vec;
typedef vector<vec> mat;
const double EPS = 1E-8;

/*---A*B^^^*/
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


/*---A^n---*/
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



/*---連立一次方程式の解(Gauss-Jordan) P257---*/
//Ax = bを解く
//解がないか一意でない場合は長さ0の配列を返す
vec gauss_jordan(const mat& A, const vec& b){
  int n = A.size();
  mat B(n, vec(n+1));
  rep(i, 0, n-1)rep(j, 0, n-1)B[i][j] = A[i][j];
  //行列Aの後ろにbを並べて同時に処理する
  rep(i,0,n-1)B[i][n] = b[i];
  
  rep(i,0,n-1){
    int pivot = i;
    rep(j,i,n-1)if(abs(B[j][i]) > abs(B[pivot][i]))pivot = j;
    swap(B[i],B[pivot]);
    
    //解がないか一意でない
    if(abs(B[i][i] < EPS)) return vec();
    
    //注目している変数の係数を1にする
    rep(j,i+1,n)B[i][j] /= B[i][i];
    rep(j,0,n-1){
      if(i != j){
        //j番目の式からi番目の変数を消去
        rep(k,i+1,n)B[j][k] -= B[j][i] * B[i][k];
      }
    }
  }
  vec x(n);
  //後ろに並べたbが解になる
  rep(i,0,n-1)x[i] = B[i][n];
  return x;
}
