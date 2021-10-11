#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

// https://atcoder.jp/contests/abc221/tasks/abc221_b
// 一回だけswap使って正しいか確認すればよかった
// ……んだと気づくまでまた無駄に時間を消費してしまった……

int main() {
  string S, T, ans = "Yes"; cin >> S >> T;
  REP (i, 0, S.size()) {
    if (S[i] != T[i]) {
      swap(S[i],S[i+1]);
      break;
    }
  }
  if (S != T) ans = "No";
  cout << ans << endl;
}