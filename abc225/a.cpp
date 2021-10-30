#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc225/tasks/abc225_a

string S;
int main() {
  cin >> S;
  int ans = 6;
  if (S.at(0) == S.at(1) && S.at(0) == S.at(2)) ans = 1;
  else if (S.at(0) == S.at(1) || S.at(0) == S.at(2) || S.at(1) == S.at(2)) ans = 3;
  cout << ans << endl;
}