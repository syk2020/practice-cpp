#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc106/tasks/abc106_b

int main() {
  int N; cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; i+=2) {
    vector<int> div;
    for (int j = 1; j <= i; ++j) {
      if (i % j == 0) div.push_back(j);
    }
    if (div.size() == 8) ++cnt;
  }
  cout << cnt << endl;
}