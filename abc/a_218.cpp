#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

/* 未参加 */
// 最初、cout << s[n-1] << endl;だけで提出して間違う羽目に
// 気を付けよう・・・・

int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << (s[n-1] == 'o' ? "Yes" : "No") << endl;
}