#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
#define ALL(x) (x).begin(),(x).end()

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_D

/* 螺旋本から */
/* 初めてスタックの使い方を知った気がする */

char ch;
int sum = 0, ans = 0;
stack<int> st1;
stack<pair<int, int>> st2;
int main() {
  // cin >> chは便利
  for (int i = 0; cin >> ch; ++i) {
    // \\にしているのは\だけだとエスケープ文字と解釈するため
    if (ch == '\\') st1.push(i);
    else if (ch == '/' && st1.size() > 0) {
      // 一番最新の\の位置をスタックから取り出す
      int j = st1.top(); st1.pop();
      // 現時点での位置(i)から前に\が出てきた時の位置(j)を引く＝水溜りの量になる
      int a = i - j;
      // すでに水溜りデータがある場合＝\\\\と続いていた場合など
      // そのデータを合算してしまう
      // first <= j の場合は山を超えているということなので無視する
      while (st2.size() > 0 && st2.top().first > j) {
        a += st2.top().second; st2.pop();
      }
      // 一番上を現時点での水溜り量で書き換える
      st2.push(make_pair(j, a));
    }
  }
  vector<int> ans;
  // ansに水溜り量を追加していく
  while (!st2.empty()) {
    ans.push_back(st2.top().second);
    sum += st2.top().second;
    st2.pop();
  }
  // 上に積まれているほど後ろの水溜り量になるので、reverseで反転する
  reverse(ALL(ans));
  cout << sum << endl;
  // 水溜りの数を出力
  cout << ans.size();
  FORE (x, ans) cout << " " << x;
  cout << endl;

}