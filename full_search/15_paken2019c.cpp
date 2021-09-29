#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
using ll = long long;

// https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c

int N, M;
int main() {
  cin >> N >> M;
  vector<vector<int>> karaoke(N, vector<int>(M));
  FORE (n, karaoke) {
    FORE (m, n) cin >> m;
  }
  ll totalpt = 0;
  REP (i, 0, M-1) {
    REP (j, i+1, M) {
      ll grouppt = 0;
      REP (k, 0, N) {
        grouppt += max(karaoke.at(k).at(i), karaoke.at(k).at(j));
      }
      totalpt = max(totalpt, grouppt);
    }
  }
  cout << totalpt << endl; 
}