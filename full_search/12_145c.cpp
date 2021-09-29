#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define ALL(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc145/tasks/abc145_c

/* 順列の全探索 */
/* 良かった、ビット全探索よりわかりやすかった */

int N;
vector<int> np;
vector<pair<int, int>> coordinate;

int main() {
  cin >> N;
  REP (i, 0, N) {
    int x, y;
    cin >> x >> y;
    coordinate.push_back(make_pair(x, y));
    np.push_back(i);
  }

  double avg = 0;
  int cnt = 0;
  do {
    REP (i, 0, N-1) {
      int X = abs(coordinate.at(np[i]).first - coordinate.at(np[i+1]).first),
      Y = abs(coordinate.at(np[i]).second - coordinate.at(np[i+1]).second);
      avg += sqrt(pow(X, 2) + pow(Y, 2));
    }
    ++cnt;
  } while (next_permutation(ALL(np)));
  cout << fixed << setprecision(8);
  cout << avg / cnt << endl;
}