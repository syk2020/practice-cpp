#include <bits/stdc++.h>
using namespace std;

/* 隣接リストの実装 */
/* DFS（深さ優先探索）を実行するのに使用する */

int N, M, A[100009], B[100009];
vector<int> G[100009];

int main() {
  cin >> N >> M;
  for (int i = 1; i < M; ++i) cin >> A[i] >> B[i];

  // 隣接リストによる表現
  // 互いの値を1つのグラフリストに隣接する値として入れ込む
  // この例は無向グラフになる
  for (int i = 1; i <= M; ++i) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  /*
  // 個人的には最初っから入れてしまってもいいような気がする
  for (int i = 1; i <= M; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  */
  // graph 出力
  for (int i = 1; i <= N; ++i) {
    cout << "G[" << i << "] = {";
    for (int j = 0; j < G[i].size(); ++j) {
      if (j >= 1) cout << ", ";
      cout << G[i][j];
    }
    cout << "}" << endl;
  }
  return 0;
}

/*
// 辺に重みがある場合
// 構造体を利用して辺を表してみる
struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  for (int = 0; i < M; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    G[from].push_back(Edge(to, weight));
  }
}
*/