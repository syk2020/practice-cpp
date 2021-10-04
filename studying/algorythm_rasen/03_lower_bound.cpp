#include <bits/stdc++.h>
using namespace std;

/* N個の整数 {a1,a2,...,aN} が与えられます。
そのとき、L≤ai+aj≤R となるような (i,j) の組の個数を求めてください。
制約：1≤N≤10^6, 1≤ai, K≤10^9,
高々 10^8 回程度の計算で実行を終わらせること */

int N, A[1000006]; long long  L, R;
int main () {
  cin >> N >> L >> R;
  for (int i = 0; i < N; ++i) cin >> A[i];
  // まずソートする
  sort(A, A+N);
  // iの値それぞれに対応するjの値を探す
  // ループで探すとN^2になるので、二分探索で数を出す
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    // 配列の何番目かを知りたいときは、配列で引くといい
    int L_j = lower_bound(A, A+N, L - A[i]) - A;
    // Rに一つ足したものからiを引いたものが該当する最大値となる
    // 1LLとしているのはRが long long の値なので合わせている
    int R_j = lower_bound(A, A+N, (R + 1LL) - A[i]) - A;
    ans += (R_j - L_j) * 1LL;
  }
  cout << ans << endl;
  return 0;
}