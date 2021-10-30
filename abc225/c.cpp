#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

// https://atcoder.jp/contests/abc225/tasks/abc225_c
/* 単純に次の業に行くときに＋７すればよかった */
/* 焦ってしまって良くない結果になっているのかなあ。終わってすぐできる問題ばっかりだ */

int N, M;
int main() {
  cin >> N >> M;
  int nm[N][M];
  REP (n, 0, N) {
    REP (m, 0, M) {
      cin >> nm[n][m];
    }
  }
  // 列数の確認とスタートの数を確認
  int col = nm[0][0] % 7 ? nm[0][0] % 7 : 7, base = nm[0][0];
  bool ans = true;
  // もし列が7を超えていたらその時点で失敗
  if (M + col > 8) ans = false;
  else {
    REP (n, 0, N) {
      if (!ans) break;
      REP (m, 0, M) {
        // baseに１ずつ足していってその数があっているか確認する
        if (nm[n][m] != base + m) {
          ans = false;
          break;
        }
      }
      // １行終わったら次の行のために＋７する
      base += 7;
    }

  }
  cout << (ans ? "Yes" : "No") << endl;
}

/*
// 問題文の意味がよくわかっていないような気がしてきた
int N, M;
int main() {
  cin >> N >> M;
  int nm[N][M];
  REP (k, 0, N) {
    REP (l, 0, M) {
      cin >> nm[k][l];
    }
  }
  int j = nm[0][0] % 7 ? nm[0][0] % 7 : 7, i = ((nm[0][0] - j) / 7) + 1, temp = j;
  bool ans = true;
  REP (k, 1, N+1) {
    if (!ans) break;
    j = temp;
    REP (l, 1, M+1) {
      if (nm[k][l] != (i-1)*7 + j) {
        ans = false;
        break;
      }
      ++j;
    }
    ++i;
  }
  cout << (ans ? "Yes" : "No") << endl;
}
*/