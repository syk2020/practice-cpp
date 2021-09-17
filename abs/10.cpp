#include <bits/stdc++.h>
using namespace std;

/* これも結構力技で解いてしまったんだけど、なんかのアルゴリズムがあるんだろうか。。。。 */
/* 絶対値を求める関数、引数と戻り値が違うらしい */
/* abs -> int型、fabs -> double型。longとfloatでも違うらしい */
/* absでdoubleを受け取ると内部でintにキャストしてから絶対値返すとか怪情報もあってもうよくわからん */

int main() {
  int N; cin >> N;
  bool ans = true;
  int oldt = 0, oldx = 0, oldy = 0;
  for (int i = 0; i < N; ++i) {
    int t, x, y; cin >> t >> x >> y;
    int dift = t - oldt, difx = abs(x - oldx), dify = abs(y - oldy);
    int checker = dift - difx - dify;
    if (checker < 0) ans = false;
    if (checker % 2 == 1) ans = false;
    oldt = t, oldx = x, oldy = y;
    if (!ans) break;
  }
  cout << (ans ? "Yes" : "No") << endl;
}

/*
// 公式解説より
// 偶奇が一致するという視点では考えてなかったけど、やってることはほぼ同じ
// 先に読み込みをしてしまうので早そう?
// でも失敗した段階で読み込み打ち切る方が早いのか？？
int main() {
  int N;
  int t[110000], x[110000], y[110000];
  cin >> N;
  t[0] = x[0] = y[0] = 0;  // 初期状態
  // 先にデータを全て読み込む
  // 0が初期状態なのでインデックス1から開始する必要あり
  for (int i = 0; i < N; ++i) cin >> t[i+1] >> x[i+1] >> y[i+1];  // 1-index にしておく

  bool can = true;
  for (int i = 0; i < N; ++i) {
    // 前のステップとの差をとる
    int dt = t[i+1] - t[i];
    // 前のステップでの位置との差をとる
    int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    // ステップ数と距離の判別、距離が大きければ実行不可
    if (dt < dist) can = false;
    // 位置の差の偶奇とステップ数の偶奇が一致するかを判別、一致していなければ実行不可
    if (dist % 2 != dt % 2) can = false;  // dist と dt の偶奇は一致する必要あり！
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
*/