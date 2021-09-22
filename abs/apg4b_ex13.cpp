#include <bits/stdc++.h>
using namespace std;

/* 範囲for文の使い方学習 */
/* 通常forの方が少し早い（7ms/8ms） */

int main() {
  int N;
  cin >> N;
  vector<int> vi(N);
  int avg = 0;
  
  /*for (int i = 0; i < N; ++i) {
  	cin >> vi.at(i);
    avg += vi.at(i);
  }*/
  // &x でvi配列という変数のアドレスを取得、直接書き込んでいるイメージ
  for (auto &x : vi) {
    cin >> x;
    avg += x;
  }
  avg /= N;
  for (auto x : vi) cout << abs(x - avg) << endl;
}
