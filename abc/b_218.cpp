#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
/* 未参加 */
/* intで読み取り -> 出力時にcharに変換 */
/* ここをしっかりしないといかん */
int main() {
  int al;
  REP (i, 26) {
    cin >> al;
    cout << (char)(al + 'a' - 1);
  }
  cout << endl;
}