#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
using ll = long long;

/* 想定できる最大量との二分探索をして、どこで一致するかを確認する問題 */
/* これは慣れていないと辛い。いい練習になった */

int N, K;
ll t[100009];

// Pがtのどのインデックスまで行くかを確認する
int check(ll P) {
  // i -> tのインデックス。外に置いてwhile内で++iとしてjとはリンクさせずに回す
  int i = 0;
  // K回繰り返して、N個全て積めるかを確かめる
  REP (j, 0, K) {
    ll s = 0;
    while(s + t[i] <= P) {
      s += t[i];
      // tのインデックスを進める
      ++i;
      // iがNになる -> これ以上進める必要がないためそのままリターン
      if (i == N) return N;
    }
  }
  return i;
}

// 二分探索
int solve() {
  // right -> 想定できる最大値、荷物の最大個数＊荷物の最大重量
  ll left = 0, right = 100000 * 10000, mid;
  // rightとleftが同じ値になるまで実施
  while (right - left > 1) {
    // mid -> 二分探索をする時の中央値
    mid = (left + right) / 2;
    // midを最大積載量として探索
    int v = check(mid);
    v >= N ? right = mid : left = mid;
  }
  return right;
}

int main() {
  cin >> N >> K;
  REP (i, 0, N) cin >> t[i];
  ll ans = solve();
  cout << ans << endl;
}