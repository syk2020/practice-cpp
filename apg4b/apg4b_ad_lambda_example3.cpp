#include <bits/stdc++.h>
using namespace std;

/* 再帰呼び出しする場合は、autoではなくfunctionと書く */
/* function<返り値の型(引数の型1, 引数の型2, ...)> 関数名 = [&](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 処理 }; */
/* 変数に代入するだけならautoでも大丈夫 */
/* functionの方が戻り値を細かく指定できるイメージ */

int main() {
  // 再帰関数の定義
  function<int(int)> sum = [&](int n) {
    if (n == 0) {
      return 0;
    }
    int s = sum(n - 1);
    return s + n;
  }; // ;必要

  cout << sum(3) << endl;

  auto autotest = [](int a, int b) {
    if (a > b) return "Yes";
  }; // ;必要
  string c = autotest(3,2);
  cout << c << endl;

  function<int(int, int)> functest = [&](int a, int b) { // 再帰でないなら[&]の&は不要
    if (a < b) return a;
  }; // ;必要
  int d = functest(2,3);
  cout << d << endl;
}
