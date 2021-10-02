#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)

// https://atcoder.jp/contests/abc122/tasks/abc122_b

/* 数が少ないのでそのままぶっつけ本番で数えてもいいらしい */
/* 公式解説の回答がよく分からなかったけど、ひとまず必ず最後にカウントをチェックするようにしたらうまくいった */

int main() {
  string S; cin >> S;
  int N = S.size();
  vector<char> ACGT{'A', 'C', 'G', 'T'};
  vector<bool> Sbool(N, false);
  REP (i, N) {
    auto it = find(ACGT.begin(), ACGT.end(), S.at(i));
    Sbool.at(i) = (it != ACGT.end()) ? true : false;
  }
  bool checker = false;
  int maincnt = 0, subcnt = 0;
  REP (i, N) {
    if (!checker) {
      if (Sbool.at(i)) {
        subcnt = 1;
        checker = true;
      }
    } else {
      if (Sbool.at(i)) ++subcnt;
      else {
        subcnt = 0;
        checker = false;
      }
    }
    // for内最後にsubcntのが大きくなっていたらmaincntに代入する式を実行
    maincnt = max(maincnt, subcnt);
  }
  cout << maincnt << endl;
}

/*
// forを一度で書いてしまう+Stringのfindとstring::nposを使ったパターン
// 行数は多いけどこっちの方が綺麗で好きかな

int main() {
  string S; cin >> S;
  int N = S.size();
  string ACGT = "ACGT";
  bool checker = false;
  int maincnt = 0, subcnt = 0;
  REP (i, N) {
    auto pos = ACGT.find(S.at(i));
    if (!checker) {
      if (pos != string::npos) {
        subcnt = 1;
        checker = true;
      }
    } else {
      if (pos != string::npos) ++subcnt;
      else {
        subcnt = 0;
        checker = false;
      }
    }
    maincnt = max(maincnt, subcnt);
  }
  cout << maincnt << endl;
}

*/