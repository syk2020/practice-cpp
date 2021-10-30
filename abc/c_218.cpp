#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

// https://atcoder.jp/contests/abc218/submissions/26812239
/* 行列の回転が面倒くさかった。。。。が、いい勉強になった */

int main() {
  int n;
  cin >> n;
  char s[n][n], t[n][n];
  int scnt = 0, tcnt = 0, spt[4] = {n,n,0,0};
  REP (i, 0, n) REP (j, 0, n) {
    cin >> s[i][j];
    if (s[i][j] == '#') {
      scnt += 1;
      spt[0] = min(spt[0], i), spt[1] = min(spt[1], j),
      spt[2] = max(spt[2], i), spt[3] = max(spt[3], j);
    }
  }
  REP (i, 0, n) REP (j, 0, n) {
    cin >> t[i][j];
    if (t[i][j] == '#') tcnt += 1;
  }
 
  bool ans = false;
  if (scnt == tcnt) {
    vector<char> sch;
    REP (i, spt[0], spt[2]+1) {
      REP (j, spt[1], spt[3]+1) sch.push_back(s[i][j]);
    }
    REP (k, 0, 4) {
      char temp;
      int end = n, i = 0;
      REP (cells, 0, n/2+1) {
        --end;
        REP (j, cells, end) {
          temp = t[n-j-1][i];
          t[n-j-1][i] = t[n-i-1][n-j-1];
          t[n-i-1][n-j-1] = t[j][n-i-1];
          t[j][n-i-1] = t[i][j];
          t[i][j] = temp;
        }
        ++i;
      }
      int tpt[4] = {n,n,0,0};
      REP (i, 0, n) REP (j, 0, n) {
        if (t[i][j] == '#') {
          tpt[0] = min(tpt[0], i), tpt[1] = min(tpt[1], j),
          tpt[2] = max(tpt[2], i), tpt[3] = max(tpt[3], j);
        }
      }
      vector<char> tch;
      REP (i, tpt[0], tpt[2]+1) {
        REP (j, tpt[1], tpt[3]+1) tch.push_back(t[i][j]);
      }
      if(sch == tch) {
        ans = true;
        break;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}
  /*
  公式解説見たけど難しい。多分、出てたら解けなかった。
  まず左上の頂点を探し、形が一致するか判定、
  そのあとSは3回９０度回転させて、それから左上から一致するか判定する全探索

  90度反時計回りに回るとき
  a1ijの位置にあったら次はa2(n-i)iに来ることになる
  行 -> n から前の位置の i を引いた位置（前の位置が２行目、Nが４なら4-2（＋1）で3行目）
  列 -> 前の位置のiが列になる（前の位置が３行目なら３列目）＼
  */

