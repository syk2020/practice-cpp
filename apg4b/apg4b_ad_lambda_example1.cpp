#include <bits/stdc++.h>
using namespace std;

/* ラムダ(lambda)式 */
/* auto 関数名 = [](引数, 引数, ...) {処理} */

int main() {
  // my_min関数をラムダ式で定義
  auto my_min = [](int a, int b) {
    if (a < b) {
      return a;
    }
    else {
      return b;
    }
  };

  cout << my_min(5, 10) << endl;
}