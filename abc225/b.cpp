#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

// https://atcoder.jp/contests/abc225/tasks/abc225_b

int N;
int main() {
  cin >> N;
  vector<vector<int>> tree(N+1);
  int a, b;
  REP (i, 0, N-1) {
    cin >> a >> b;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }

  string ans = "No";
  REP (i, 1, N+1) {
    int siz = size(tree.at(i));
    if (siz >= N-1) ans = "Yes";
  }
  cout << ans << endl;
}