#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(x, a) for (auto &x : a)

// https://atcoder.jp/contests/abc128/tasks/abc128_c
/* ビット全探索の練習 */
/* コードを読めば理解はできる */
/* けど実際に書くのはかなり大変。慣れが必要 */

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> lights(M);
  // 各ライトが対応するスイッチを格納
  // ビット探索するときに0から検索をしたいので読み込んだ後に--すること
  REP (i, 0, M) {
    int k, s; cin >> k;
    REP (j, 0, k) {
      cin >> s; lights.at(i).push_back(--s);
    }
  }
  // 各ライトのスイッチが偶奇どちらで点灯するのか格納
  vector<int> oddeven(M, 0);
  for (auto &x : oddeven) cin >> x;
  // bitによる全探索
  int ans = 0;
  for (int bit = 0; bit < (1<<N); ++bit) {
    int ok = 0;
    for (int i = 0; i < M; ++i) {
      int cnt = 0;
      // 各ライト毎に対応するスイッチが付いているかどうか
      for (auto &x : lights.at(i)) {
        // ついていたらカウント
        if (bit & (1 << x)) ++cnt;
      }
      // 各ライト毎に対応するスイッチのうち、ONになっているものの数->cnt
      // cntとoddevenの偶奇が一致している->ライトがついている
      if (cnt%2 == oddeven.at(i)) ++ok;
    }
    // okの数->ついているライトの数
    // ok == M -> 全てのライトがついている
    if (ok == M) ++ans;
  }
  cout << ans << endl;
}

  /*
  // 15行目以降をマクロで書き下す

  vector<int> oddeven(M, 0);
  FORE (x, oddeven) cin >> x;

  int ans = 0;
  REP (bit, 0, 1<<N) {
    int ok = 0;
    REP (i, 0, M) {
      int cnt = 0;
      FORE (x, lights.at(i)) if (bit & (1 << x)) ++cnt;
      if (cnt % 2 == oddeven.at) ++ok;
    }
    if (ok == M) ++ans;
  }
  */
