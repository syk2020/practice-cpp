#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
int main() {
  string contest[4] = {"ABC", "ARC", "AGC", "AHC"};
  string cs[3];
  cin >> cs[0] >> cs[1] >> cs[2];
  REP(i, 4) {
    auto result = find(cs, cs+3, contest[i]);
    if (result == cs+3) {
      cout << contest[i] << endl;
      break;
    }
  }

  /*
  イテレータを理解しておらず、Findの戻り値がただのインデックスだと思っていた
  （追加で、引数の書き方もよくわかっていなかった）ので、
  そこの確認でものすごい時間がかかってしまった問題
  */

}