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

/*
// 公式解説より
// 各桁の和を計算する関数
// これを使った方がよっぽどスマート！

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int total = 0;
  for (int i = 1; i <= N; ++i) {
    int sum = findSumOfDigits(i); // i の各桁の和
    if (sum >= A && sum <= B) { //  i の各桁の和が A 以上 B 以下かどうか
      total += i;
    }
  }
  cout << total << endl;
}
*/