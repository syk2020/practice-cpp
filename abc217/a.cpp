#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); i++)
int main() {
  string s, t;
  cin >> s >> t;
  if (s < t) cout << "Yes" << endl;
  else cout << "No" << endl;
  /*
  // 最後は三項演算子で書ける
  cout << (s < t ? "Yes" : "No") << endl;
  */
}