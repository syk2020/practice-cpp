#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)

// https://atcoder.jp/contests/abc222/tasks/abc222_b

// 冷静になると別に配列に格納する必要はないことがよくわかる。。。

int main() {
  int N, P; cin >> N >> P;
  int cnt = 0;
  REP (i, 0, N) {
    int p; cin >> p;
    if (p < P) cnt++;
  }
  cout << cnt << endl;
}

/*
int main() {
  int N, P; cin >> N >> P;
  vector<int> points;
  REP (i, 0, N) {
    int p; cin >> p;
    points.push_back(p);
  }
  int cnt = 0;
  FORE (x, points) {
    if (x < P) cnt++;
  }
  cout << cnt << endl;
}
*/