#include <bits/stdc++.h>
using namespace std;

/* BFS（幅優先探索）を実行するときに */
/* 迷路の最小移動回数を求めるときなど */

int H, M; // 迷路の大きさ
char c[1009][1009];
int dist[1009][1009];

int main() {
  cin >> H >> M;
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= M; ++j) cin >> c[i][j];
  }
  // 距離をMAX値にしておく
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= M; ++j) dist[i][j] = INT_MAX;
  }

  // 進行方向の候補をキューへ詰める
  // -> 進行方向の候補として出てきた順に探索するので幅優先探索となる
  queue<pair<int, int>> Q;
  Q.push(make_pair(1, 1));
  // 初期値を設定
  dist[1][1] = 0;

  while (!Q.empty()) {
    // 現在位置を確認する
    int cx = Q.front().first, cy = Q.front().second;
    Q.pop();
    // 進行方向をforで操作しやすくするために配列で座標方向を定める（上、右、下、左の順）
    int dx[4] = {1, 0, -1, 0}; // xの進行方向
    int dy[4] = {0, 1, 0, -1}; // yの進行方向
    for (int i = 0; i < 4; ++i) {
      int ex = cx + dx[i], ey = cy + dy[i];
      // 移動先候補が.（ブロック）、もしくはすでに値が定まっていた場合はスルーして次へ
      if (c[ex][ey] != '.' || dist[ex][ey] != INT_MAX) continue;
      dist[ex][ey] = dist[cx][cy] + 1;
      Q.push(make_pair(ex, ey));
    }
  }

  /*
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (j >= 2) cout << " ";
      cout << dist[i][j];
    }
    cout << endl;
  }
  */
  // 最短距離を出力
  cout << dist[H][M] << endl;
  return 0;
}