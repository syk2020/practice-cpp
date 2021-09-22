#include <bits/stdc++.h>
using namespace std;

/* 多次元配列初期化方法：vector<vector<int> vvi(5, vector<int>(5)) */
/* -> 5*5の配列ができる */
/* vector<vector<int> vvi(4, vector<int>(3)) */
/* -> 4*3の配列ができる */
/* vvi.at(x).at(y) -> x行y列の要素取得 */

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<string>> vvs(N, vector<string>(N, "-"));
  for (int i = 0; i < M; i++) {
    vvs.at(A.at(i)-1).at(B.at(i)-1) = "o";
    vvs.at(B.at(i)-1).at(A.at(i)-1) = "x";
  }
  for (int i = 0; i < N; i++) {
	  for (int j = 0; j < N; j++) {
      cout << vvs.at(i).at(j) << " \n"[j == N-1];
    }
  }
}
