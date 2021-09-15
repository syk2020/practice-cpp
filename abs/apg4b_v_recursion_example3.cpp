#include <bits/stdc++.h>
using namespace std;

/* 再帰関数`func`は、「引数のnを1減らして再帰呼出しをn=0になるまで行い、呼び出し履歴を出力する」関数 */
/* space, print_in, print_out はおまけ。基本はfuncの呼び出しにかかっている */
/* 階層を出すためにdepthを引数にしてspaceでインデントを作成している */

// num個分のスペースからなる文字列を返す (字下げに用いる)
// depth*4として、字下げ用に使用する
string space(int num) {
  string ret = "";
  for (int i = 0; i < num; i++) {
    ret += " ";
  }
  return ret;
}

// 呼び出しの深さに応じて字下げし、関数の開始時点であるというメッセージを出力
void print_in(int n, int depth) {
  cout << space(depth * 4) << "func(" << n << ", " << depth << ") in" << endl;
}

// 呼び出しの深さに応じて字下げし、関数の終了時点であるというメッセージを出力
void print_out(int n, int depth) {
  cout << space(depth * 4) << "func(" << n << ", " << depth << ") out" << endl;
}

// n: 何回の再帰呼出しを行うか
// depth: 呼び出しの深さ(何回目の再帰呼び出しか)
void func(int n, int depth) {
  // ベースケース
  if (n == 0) {
    print_in(n, depth);   // 開始
    print_out(n, depth);  // 終了
    return;
  }

  // 再帰ステップ
  print_in(n, depth);  // 開始
  func(n - 1, depth + 1);  // 残り回数を1減らし、呼び出しの深さを1増やす
  print_out(n, depth); // 終了
}

int main() {
  func(3, 0);  // 3回の再帰呼び出しを行う, 初めの深さを0とする
}
