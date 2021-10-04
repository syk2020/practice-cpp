#include <bits/stdc++.h>
using namespace std;

/* N 本の棒があり、i 番目の棒の長さは li です。
あなたは N 本の中から K 本の棒を選び、それをつなげることで、ヘビのおもちゃを作りたいです。
ヘビのおもちゃの長さは、選んだ棒の長さの総和で表されます。ヘビの長さとしてあり得る最大値を求めてください。
制約：1≤K≤N≤10^6, 1≤li≤10^9, 1≤K≤N≤10^6, 1≤li≤10^9、
高々 10^8 回程度の計算で実行を終わらせること */

long long N, K, L[10009];
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> L[i];
  // 並べ替え
  sort(L, L + N);
  long long ans = 0;
  // 一番長い棒から、N-1番目に長い棒までを取る
  for (int i = N-1; i >= 0; ++i) ans += L[i];
  cout << ans << endl;
  return 0;
}