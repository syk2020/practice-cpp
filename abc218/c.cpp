#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
/* 未参加 */
// とりあえず#の数が違う→絶対できない、まではわかったけどこの先がわからないのでギブアップ
int main() {
  int n;
  cin >> n;
  char s[n][n];
  char t[n][n];
  int scnt = 0, tcnt = 0;
  REP (i, n) REP (j, n) {
    cin >> s[i][j];
    if (s[i][j] == '#') scnt += 1;
  }
  REP (i, n) REP (j, n) {
    cin >> t[i][j];
    if (t[i][j] == '#') tcnt += 1;
  }
  if (scnt != tcnt) {
    cout << "No" << endl;
  } else {
    //
  }

  /*
  公式解説見たけど難しい。多分、出てたら解けなかった。
  まず左上の頂点を探し、形が一致するか判定、
  そのあとSは3回９０度回転させて、それから左上から一致するか判定する全探索
  */

}