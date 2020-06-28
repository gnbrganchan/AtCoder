// 自作の行列構造体
template<typename T>
struct mat {
    // 行列m
    vector<vector<T>> m;
    // コンストラクタ:第1引数⇒行数、第2引数⇒列数、第3引数⇒初期値
    mat():m(vector<vector<T>>()){}
    mat(int h,int w):m(vector<vector<T>>(h,vector<T>(w))){}
    mat(int h,int w, T d):m(vector<vector<T>>(h,vector<T>(w,d))){}
    // 添字演算子
    vector<T> operator[](const int i) const {return m[i];} //読み取り
    vector<T>& operator[](const int i){return m[i];} //書き込み
    // 行数・列数
    int nrow = sz(m);
    int ncol = sz(m[0]);
    // 行列同士の演算
    mat& operator=(const mat& a){return *a;}
    mat& operator+=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
    mat& operator-=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;} 
    mat& operator*=(const mat& a){assert(ncol == a.nrow);mat<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol)m2[i][j] += m[i][k]*a[k][j];ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]; return *this;}
    mat operator+(const mat& a) const { return mat(*this) += a;}
    mat operator-(const mat& a) const { return mat(*this) -= a;}
    mat operator*(const mat& a) const { return mat(*this) *= a;}
    bool operator==(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}
    // 行列とスカラの演算
    mat& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
    mat& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
    mat& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
    mat& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
    mat operator+(const T& a) const { return mat(*this) += a;}
    mat operator-(const T& a) const { return mat(*this) -= a;}
    mat operator*(const T& a) const { return mat(*this) *= a;}
    mat operator/(const T& a) const { return mat(*this) /= a;}
    // 回転（degの数だけ時計回りに90度回転）
    mat& rot(int deg){
        mat<T> m2(ncol, nrow);
        if(deg == 1 || deg == 3){
            if(deg == 1)rep(i,nrow)rep(j,ncol)m2[j][nrow -i -1] = m[i][j];
            if(deg == 3)rep(i,nrow)rep(j,ncol)m2[ncol -j -1][i] = m[i][j];
            swap(ncol,nrow); // 列数と行数を入れ替える
            m.resize(nrow);rep(i,nrow)m[i].resize(ncol); //リサイズ
        }
        if(deg == 2)rep(i,nrow)rep(j,ncol)m2[nrow -i -1][ncol -j -1] = m[i][j];
        rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j];
        return *this;
    }
    // 標準出力
    void show(){
        rep(i,nrow)rep(j,ncol){
            if(j != 0)cout << " ";
            cout << m[i][j];
            if(j==ncol-1)cout << endl;
        }
        return ;
    }
};


// from あり本

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
