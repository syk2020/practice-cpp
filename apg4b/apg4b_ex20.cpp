#include <bits/stdc++.h>
using namespace std;

/* 基本はrecursion_example1と同じ */
/* その会社自体も報告書を出す必要があるので、returnは1を返す必要がある */

// x番の組織が親組織に提出する枚数を返す
// childrenは組織の関係を表す2次元配列(参照渡し)
int count_report_num(vector<vector<int>> &children, int x) {
  // (ここに追記して再帰関数を実装する)
  if (children.at(x).size() == 0) return 1;

  // children(x)到達時点の時間をメモする配列を作成
  vector<int> memo(children.at(x).size());

  // 再帰
  // childrenに子要素があるとき、子要素へアクセスして子要素からの数値を受け取る
  for (int i = 0; i < children.at(x).size(); ++i) {
    // 引数のxはインデックスなので、children.at(x)の配列の中身を回す
    memo.push_back(count_report_num(children, children.at(x).at(i)));
  }

  int result = 1;
  for (auto x : memo) result += x;

  // 値を返す
  return result;
}

// これ以降の行は変更しなくてよい

int main() {
  int N;
  cin >> N;

  vector<int> p(N);  // 各組織の親組織を示す配列
  p.at(0) = -1;  // 0番組織の親組織は存在しないので-1を入れておく
  for (int i = 1; i < N; i++) {
    cin >> p.at(i);
  }

  // 組織の関係から2次元配列を作る
  vector<vector<int>> children(N);  // ある組織の子組織の番号一覧
  for (int i = 1; i < N; i++) {
    int parent = p.at(i);  // i番の親組織の番号
    children.at(parent).push_back(i);  // parentの子組織一覧にi番を追加
  }

  // 各組織について、答えを出力
  for (int i = 0; i < N; i++) {
    cout << count_report_num(children, i) << endl;
  }
}
