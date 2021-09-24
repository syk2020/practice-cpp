#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
using ll = long long;

// https://atcoder.jp/contests/abc144/tasks/abc144_b

int main() {
  int N; cin >> N;
  string ans = "No";
  if (N <= 81) {
    REP (i, 1, 10) {
      REP (j, 1, 10) {
        if (N == i*j) ans = "Yes";
      }
      if (ans == "Yes") break;
    }
  }
  cout << ans << endl;
}