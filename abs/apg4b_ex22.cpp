#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int>> vp(N);
  for (auto &x : vp) cin >> x.second >> x.first;
  sort(vp.begin(), vp.end());
  for (auto x : vp) cout << x.second << " " << x.first << endl;
}

/*
// ちゃんとpair型の仕組みを覚えるためにも、一個一個分解した方が良かったかも知れぬ

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> p(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    // make_pair で pair型を作る
    p.at(i) = make_pair(b, a);  // b, a の順でペアにする
  }

  sort(p.begin(), p.end());

  for (int i = 0; i < N; i++) {
    int b, a;
    // tie(b, a) でp.at(i)を分ける
    // pair型 : first -> b, second -> a 
    tie(b, a) = p.at(i);  // b, a の順であることに注意
    cout << a << " " << b << endl;
  }
}

*/