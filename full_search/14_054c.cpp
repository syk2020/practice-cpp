#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
#define ALL(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc054/tasks/abc054_c

/* count関数がとても使いやすいと声を大にして言いたい */
/* pp = {0, 7, 6, 5, 4, 3, 2, 1}としてprev_permutationにする */
/* -> if (np.at(0) != 0) break; が不要になるのでこれもアリか？ */

int N, M;
int node, branch;

int main() {
  cin >> N >> M;
  vector<int> path[N], np;
  REP (i, 0, M) {
    cin >> node >> branch, --node, --branch;
    path[node].push_back(branch);
    path[branch].push_back(node);
  }
  REP (i, 0, N) np.push_back(i);
  int cnt = 0;
  do {
    if (np.at(0) != 0) break;
    bool ok = true;
    REP (i, 0, N-1) {
      vector<int> vp = path[np.at(i)];
      if (!count(ALL(vp), np.at(i+1))) {
        ok = false; break;
      }
    }
    if (ok) ++cnt;
  } while (next_permutation(ALL(np)));
  cout << cnt << endl;
}