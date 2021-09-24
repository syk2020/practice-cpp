#include <bits/stdc++.h>
using namespace std;

/* テンプレートを用いたchmax/chmin関数 */
/* 引数の値が大きければa（第一引数）の値を更新する */
/* 動的計画法とかで使う */
/* 関数の一般化（引数がintでもdoubleでも同じ動作をする、など）や、構造体も作れる */

// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

//-------------------------------

int f(int n) {
  // (適当な関数)
  return n * n - 8 * n + 3;
}

int main() {
  // f(1), f(2), ..., f(10)の最小値と最大値を求める
  int ans_min = 1000000000;
  int ans_max = 0;
  for (int i = 1; i <= 10; i++) {
    chmin(ans_min, f(i));  // 最小値を更新
    chmax(ans_max, f(i));  // 最大値を更新
  }
  cout << ans_min << " " << ans_max << endl;
}
