#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc095/tasks/arc096_a
/* これも全探索の一つ */
/* でもほぼ力技で解決してて探索してない。。。。 */

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int price = INT_MAX;
  int checker = A*X + B*Y;
  price = min(price, checker);
  checker = 2*C * max(X, Y);
  price = min(price, checker);
  checker = 2*C * min(X, Y);
  checker += (X > Y) ? A * (X - Y) : B * (Y - X);
  price = min(price, checker);
  cout << price << endl;
}

/*
// 公式解説より
// ３種類のどれかをi個買った結果、他の2つが幾つになるかは自動で決まるので探索をかける
// な、なるほど……（全然気づかんかった）

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int price = INT_MAX;
  // i <= max(X, Y)*2　`<=` にしておくことを注意
  for (int i = 0; i <= max(X, Y)*2; i+=2) {
    // abピザを買った分（2の倍数になっている）
    int sum = C * i;
    // aピザ残り必要数
    int a = X - i / 2;
    // bピザ残り必要数
    int b = Y - i / 2;
    // aピザbピザを必要枚数購入した分を加算
    if (a > 0) sum += a * A;
    if (b > 0) sum += b * B;
    price = min(price, sum);
  }
  cout << price << endl;
}
*/