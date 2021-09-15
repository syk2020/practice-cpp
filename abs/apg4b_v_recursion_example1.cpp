#include <bits/stdc++.h>
using namespace std;

/* 再帰の例題 */
/* 木構造にすることも、何を持って再帰にするかも思いつかなかった */
/* 再帰関数だけ書けば良かったのでできたけど、そこに至るまでもきちんと復習すること */

// x番の組織について、子組織からの報告書が揃った時刻を返す
// childrenは組織の関係を表す2次元配列(参照渡し)
int complete_time(vector<vector<int>> &children, int x) {
  // (ここに追記して再帰関数を実装する)
  
  // children -> 木構造のvector, x -> 参照しているインデックス
  
  // ベースケース
  // children.at(x)に子要素がない
  // 到達時間=0として０を返す
  if (children.at(x).size() == 0) return 0;

  // children(x)到達時点の時間をメモする配列を作成
  vector<int> memo(children.at(x).size());

  // 再帰
  // childrenに子要素があるとき、子要素へアクセスして子要素からの数値を受け取る
  for (int i = 0; i < children.at(x).size(); ++i) {
    // 引数のxはインデックスなので、children.at(x)の配列の中身を回す
    memo.push_back(complete_time(children, children.at(x).at(i)));
  }

  // アクセスしてきたものと子要素全て到達数を比べる
  // 一番大きい物を選ぶ
  // max_elementはイテレータを返すので、頭に*をつける
  int result = *max_element(memo.begin(), memo.end());

  // 一番大きいものに+1する
  // 値を返す
  return ++result;
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

  // 組織の関係から2次元配列を作る(理解しなくてもよい)
  vector<vector<int>> children(N);  // ある組織の子組織の番号一覧  // N×0の二次元配列
  for (int i = 1; i < N; i++) {
    int parent = p.at(i);  // i番の親組織の番号
    children.at(parent).push_back(i);  // parentの子組織一覧にi番を追加
  }

  // 0番の組織の元に報告書が揃う時刻を求める
  cout << complete_time(children, 0) << endl;
}
