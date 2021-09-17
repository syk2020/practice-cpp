#include <bits/stdc++.h>
using namespace std;

/* int <char型> の時は、'0'('a', 'A')で引かないと意図した答えにならない */
/* そんなに難しくないけど最後何を足し上げたものをansとするかを間違えた */
/* 上記２点でものすごく時間を使ってしまった。反省 */

int main() {
  int n, a, b, ans = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    string s = to_string(i);
    for (int j = 0; j < s.size(); ++j) {
      sum += (int)s[j]-'0';
    }
    if (a <= sum && sum <= b) ans += i;
  }
  cout << ans << endl;
  return 0;
}