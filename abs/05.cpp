#include <bits/stdc++.h>
using namespace std;

/* ちょっと考えてもよくわからなくなってしまったので回答みたら三重ループで良かったんだ。。。。 */
/* そんな日は寝た方がいい */

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  if (!(x % 100 == 50 && c == 0) && (x < 500*a + 100*b + 50*c)) {
    for (int i = 0; i <= a; i++) {
      for (int j = 0; j <= b; j++) {
        for (int k = 0; k <= c; k++) {
          if (500*i + 100*j + 50*k == x) ++ans;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}