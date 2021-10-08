#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

int N;
set<string> dict;
int main() {
  cin >> N;
  string m, str;
  REP (i, 0, N) {
    cin >> m >> str;
    if (m == "insert") dict.insert(str);
    else {
      int cnt = dict.count(str);
      if (cnt > 0) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
  return 0;
}