#include <bits/stdc++.h>
using namespace std;

/* 再帰の問題かと思ったけど、計算量の問題だった */
/* 最後、1000札は（N-x-y）で出るからループは要らないよね、そこはループせずに切りましょうって話 */
/* 基本的には05.cppと同じ */
/* forの最大値は x <= N で <= なのもハマりポイントなので忘れずに */

int main() {
  int N, Y, ans10000 = -1, ans5000 = -1, ans1000 = -1;
  cin >> N >> Y;
  for (int x = 0; x <= N; ++x) {
    for (int y = 0; y <= (N - x); ++ y) {
      if (10000 * x + 5000 * y + 1000 * (N - x - y) == Y) {
        ans10000 = x; ans5000 = y; ans1000 = N - x - y;
      }
    }
  }
  cout << ans10000 << " " << ans5000 << " " << ans1000 << endl;
}

/*
最初に書いてたもの
なんかこの手の問題、再帰を使わなきゃいけない気がしてしまう
bool func(int i, int w, vector<int> &data) {
  // i -> 残り枚数　 0になった時がベースケース
  // w -> 残り金額　 i == 0 の時、w == 0ならばtrueを返せる
  // data -> 各枚数　data.at(0), data.at(1), data.at(2)の総和はNになるはず

  bool ans = false;
  if (i == 0) return true;
  // for で10000、5000、1000のどれかを増やしていく
  // dataのどれかが増える度、iは減っていく
  for (int j = 0; j < 3; j++) {
    w -= (10000 * data.at(0) + 5000 * data.at(1) + 1000 * data.at(2));
    data.at(j) += 1;
    --i;
    cout << i << " " << w << " " << data.at(0) << " " << data.at(1) << " " << data.at(2) << endl;
  }
  return ans;
}

int main() {
  int N, YEN;
  cin >> N >> YEN;
  vector<int> v(3, 0);
  if (YEN <= 10000*N && YEN >= 1000*N){
    if (!func(N, YEN, v)) {
      v.assign(3, -1);
    }
  }
  cout << v.at(0) << " " << v.at(1) << " " << v.at(2) << endl;
  return 0;
}
*/