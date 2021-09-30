#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define ALL(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
/* 最後は二分探索で、forで回しちゃダメだったのね */
/* にしてもこの計算式、もう少しゴツくない書き方できないものか。。。。 */
/* 中心点も求めずに計算したいけどどうしたらいいんだろ */

int N;
// 中心点を求めるときに0.5が発生するので最初からdoubleで実装
vector<pair<double, double>> point;
int main() {
  cin >> N;
  REP (i, 0, N) {
    double x, y; cin >> x >> y;
    point.push_back(make_pair(x, y));
  }
  // 二分探索をかけるためにソートを実行する
  sort(ALL(point));
  double maxS = 0;
  REP (i, 0, N-1) {
    REP (j, i+1, N) {
      pair<double, double> loc1 = point.at(i), loc2 = point.at(j), loc3, loc4, center;
      center.first = (loc1.first + loc2.first) / 2;
      center.second = (loc1.second + loc2.second) / 2;
      double S = (pow(abs(loc1.first - loc2.first), 2) + pow(abs(loc1.second - loc2.second), 2)) / 2;
      double xdiff = loc1.first - center.first, ydiff = loc1.second - center.second;
      loc3 = make_pair(center.first - ydiff, center.second + xdiff);
      loc4 = make_pair(center.first + ydiff, center.second - xdiff);
      // loc3, loc4はすでに位置を求めているので配列から探す必要はなく、存在しているかを確認するだけでOK
      // pointとloc3, loc4の型は同じである必要があるので、double/intどちらかに寄せておくこと
      bool is_loc3 = binary_search(ALL(point), loc3);
      bool is_loc4 = binary_search(ALL(point), loc4);
      if (is_loc3 && is_loc4) maxS = max(maxS, S);
    }
  }
  cout << (int)maxS << endl;
}

/*
// TLEなので最後のFORをソート->lower_boundで探るとこまでは把握した
// が、データ構造的になんかうまいこと行かないので困った
// -> lower_bound/binary_searchともにintのpairでdoubleのpairを探していたことが敗因
// 　　最初からdoubleに統一すれば良かった
int N;
vector<pair<int, int>> point;
int main() {
  cin >> N;
  REP (i, 0, N) {
    int x, y; cin >> x >> y;
    point.push_back(make_pair(x, y));
  }
  sort(ALL(point));
  int maxS = 0;
  REP (i, 0, N-1) {
    REP (j, i+1, N) {
      pair<double, double> loc1 = point.at(i), loc2 = point.at(j), center;
      center.first = (loc1.first + loc2.first) / 2;
      center.second = (loc1.second + loc2.second) / 2;
      int S = (pow(abs(loc1.first - loc2.first), 2) + pow(abs(loc1.second - loc2.second), 2)) / 2;
      double xdiff = loc1.first - center.first, ydiff = loc1.second - center.second;
      bool is_loc3 = false, is_loc4 = false;
      REP (k, 0, N) {
        if (k == i || k == j ) continue;
        if (k > j) break;
        pair<double, double> comp = point.at(k);
        if (comp == make_pair(center.first - ydiff, center.second + xdiff)) is_loc3 = true;
        if (comp == make_pair(center.first + ydiff, center.second - xdiff)) is_loc4 = true;
        if (is_loc3 && is_loc4) maxS = max(maxS, S);
      }
    }
  }
  cout << maxS << endl;
}
*/