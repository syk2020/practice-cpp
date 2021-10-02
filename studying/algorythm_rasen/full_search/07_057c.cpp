#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// https://atcoder.jp/contests/abc057/tasks/abc057_c

// B = (long long)N / (int)A なので、long longになる可能性がある
// max(A, B) の中身を同じ型に揃えるため、どちらも long long型に変更しておく
int digits (ll A, ll B) {
  return to_string(max(A, B)).size();
}

int main() {
  ll N; cin >> N;
  // Nの平方根までを入れる配列なのでvector<int>でOK
  vector<int> div;
  div.push_back(1);
  if (N % 2 == 0) div.push_back(2);
  // 平方根までしか確認しないことにより、計算量を抑える
  for (int i = 3; i <= abs(sqrt(N)); i+=2) {
    if (N % i == 0) div.push_back(i);
  }
  int mindigits = INT_MAX;
  int len = div.size();
  REP (i, len) mindigits = min(mindigits, digits(div.at(i), N / div.at(i)));
  cout << mindigits << endl;
}