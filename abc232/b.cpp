#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

/* z->aで数値がおかしくなるのを26で割った余りにするのに思いつくのがすごい時間かかった。。。。 */

string s, t;
int main() {
  cin >> s >> t;
  int diff = (t[0] - s[0] + 26) % 26;

  bool frag = true;
  REP(i, 0, int(s.size())) {
    if (!frag) break;
    frag = (int(s[i] - 'a' + diff) % 26 == int(t[i] - 'a') % 26) ? true : false;
  }
  cout << (frag ? "Yes" : "No") << endl;
}