#include <bits/stdc++.h>
using namespace std;

/* 最短経路問題、ダイクストラ法 */
/* 頂点Sから各頂点への最短距離を求める */
/* 重み付き無向グラフの場合を想定 */

// N -> 頂点の数, M -> 枝の数, S -> 頂点をどこにするか
int N, M, S, A[500009], B[500009], C[500009];
int dist[100009];
vector<pair<int, int>> G[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

// A, B, Cはわざわざ配列にしなくてもいいような
// こっちの方が早いのだろうか
int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    cin >> A[i] >> B[i] >> C[i];
    G[A[i]].push_back(make_pair(B[i], C[i]));
    G[B[i]].push_back(make_pair(A[i], C[i]));
  }
  cin >> S;

  for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;

  // 最初の頂点Sのデータを入れる
  Q.push(make_pair(0, S));
  dist[S] = 0;
  while (!Q.empty()) {
    // secondには調べる頂点が入っている
    int pos = Q.top().second; Q.pop();
    for (int i = 0; i < G[pos].size(); ++i) {
      // to -> 
      int to = G[pos][i].first, cost = G[pos][i].second;
      if (dist[to] > dist[pos] + cost) {
        dist[to] = dist[pos] + cost;
        Q.push(make_pair(dist[to], to));
      }
    } 
  }
}