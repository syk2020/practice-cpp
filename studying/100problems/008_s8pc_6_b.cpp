#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define ALL(x) (x).begin(),(x).end()
using ll = long long;

// https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b

/* 中央値が一番少なくなるってのは何となくでしかわからなかった。。。 */
/* 中央値の出し方 -> 奇数：(N-1)/2、偶数：(A.at(N/2-1) + A.at(N/2)) / 2 */
/* インデックスが０から始まっていることに注意 */
/* forのインデックスを間違えてしまったり、今日はもうダメぽな感じ。。。 */

int N;
ll dist = 0, a, b, ent_p, end_p;
vector<ll> A, B;
int main() {
  cin >> N;
  REP (i, 0, N) {
    cin >> a >> b;
    A.push_back(a);
    B.push_back(b);
    dist += b-a;
  }
  /*
  // 中央値を出して計算する場合
  sort(ALL(A)); sort(ALL(B));
  ent_p = (N % 2 == 0) ? (A.at(N/2-1) + A.at(N/2)) / 2 : A.at((N-1)/2);
  end_p = (N % 2 == 0) ? (B.at(N/2-1) + B.at(N/2)) / 2 : B.at((N-1)/2);
  REP (i, 0, N) dist += abs(A.at(i) - ent_p) + abs(B.at(i) - end_p);
  */
  // マス目からの全探索
  ll ent_dist = LONG_MAX, end_dist = LONG_MAX;
  REP (i, 0, N) {
    ll ent_comp = 0, end_comp = 0;
    ent_p = A.at(i); end_p = B.at(i);
    REP (j, 0, N) {
      ent_comp += abs(A.at(j) - ent_p);
      end_comp += abs(B.at(j) - end_p);
    }
    ent_dist = min(ent_dist, ent_comp);
    end_dist = min(end_dist, end_comp);
  }
  dist += ent_dist + end_dist;

  cout << dist << endl;
}