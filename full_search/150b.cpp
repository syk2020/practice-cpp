#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc150/tasks/abc150_b

int main() {
  int N; string S; cin >> N >> S;
  int cnt = 0;
  // N-2として存在しない文字列インデックスを読み込みに行かないようにする
  for (int i = 0; i < N-2;) {
    if (S.at(i) == 'A' && S.at(i+1) == 'B' && S.at(i+2) == 'C') {
      ++cnt; i += 3;
    } else ++i;
  }
  cout << cnt << endl;
}