#include <bits/stdc++.h>
using namespace std;

/* 迷路をゴールできるか再帰で調べる */
/* よくある再帰の代表例（だと思ってる）ので、よく復習 */
/* 元のデータとチェック済みの箇所のデータを調べる必要があるので、引数としてはどちらも取ること */

// 正しい移動かを調べる (y, x)が移動先
// boardもcheckedも参照渡し
// かつ、boardは一次元配列であることを把握
bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  // 渡されたボードの大きさを把握
  int N = board.size();

  // 移動先がマス目の外である場合
  if (x <= -1 || x >= N || y <= -1 || y >= N) {
    return false;
  }
  // 移動先が壁マス
  // -> board.at(y)はvectorの配列インデックス、.at(x)はstringの配列インデックス
  if (board.at(y).at(x) == '#') {
    return false;
  }
  // 既に調べているマスへの移動は調べないのでfalseを返す
  if (checked.at(y).at(x)) {
    return false;
  }

  // それ以外なら正しい移動
  return true;
}

// (y, x)にいる状態からゴールに到達できるか
// board: マス目の種類
// checked: そのマスを既に調べたかを持つ二次元配列
bool reachable(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int N = board.size();

  // ベースケース
  if (x == N - 1 && y == N - 1) {
    // ゴールにいる状態
    return true;
  }

  // 再帰ステップ

  checked.at(y).at(x) = true;  // 既に調べているという状態に変えておく

  // 「上」「右」「下」「左」のいずれかの移動でゴールに到達できるか？
  bool result = false;
  
  // 上右下左の４箇所それぞれで行けるか確認する
  // 再帰を使用→今いるマスから一つ先に行けるか確認→再帰とやっていく

  // 上へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
    result = true;
  }
  // 右へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x + 1, y) && reachable(board, checked, x + 1, y)) {
    result = true;
  }
  // 下へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x, y + 1) && reachable(board, checked, x, y + 1)) {
    result = true;
  }
  // 左へ移動したマスからゴールに到達できるか？
  if (is_valid_move(board, checked, x - 1, y) && reachable(board, checked, x - 1, y)) {
    result = true;
  }

  return result;
}

int main() {
  int N;
  cin >> N;
  // マス目の状態を受け取る
  // 配列が一次元であることに注意
  vector<string> board(N);
  for (int i = 0; i < N; i++) {
    cin >> board.at(i);
  }

  // 既にそのマスを調べたかを保持する二次元配列
  vector<vector<bool>> checked(N, vector<bool>(N, false));  // false(まだ調べていない)で初期化しておく

  // (0, 0) からゴールまで到達できるか？
  if (reachable(board, checked, 0, 0)) {
    cout << "Yes" << endl;
  }
    else {
    cout << "No" << endl;
  }
}
