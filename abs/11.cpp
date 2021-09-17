#include <bits/stdc++.h>
using namespace std;

/* これも結構力技で解いてしまったんだけど、なんかのアルゴリズムがあるんだろうか。。。。 */

int main() {
  int N; cin >> N;
  bool ans = true;
  int oldt = 0, oldx = 0, oldy = 0;
  for (int i = 0; i < N; ++i) {
    int t, x, y; cin >> t >> x >> y;
    int dift = t - oldt, difx = fabs(x - oldx), dify = fabs(y - oldy);
    int checker = dift - difx - dify;
    if (checker < 0) ans = false;
    if (checker % 2 == 1) ans = false;
    oldt = t, oldx = x, oldy = y;
    if (!ans) break;
  }
  cout << (ans ? "Yes" : "No") << endl;
}
