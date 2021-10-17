#include <bits/stdc++.h>
using namespace std;

/* グラフの問題。なるほど、わからん */
/* もうちょっと後にします… */

/*
// 公式解説
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> indeg(N);
    vector<vector<int>> out(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        indeg[b] += 1;
        out[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < N; ++i) {
        if (indeg[i] == 0) {
            heap.push(i);
        }
    }
    vector<int> ans;
    ans.reserve(N);
    while (!heap.empty()) {
        int i = heap.top();
        heap.pop();
        ans.push_back(i);
        for (int j : out[i]) {
            indeg[j] -= 1;
            if (indeg[j] == 0) {
                heap.push(j);
            }
        }
    }
    if (size(ans) != N) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < N; ++i) {
            cout << ans[i] + 1 << (i + 1 == N ? '\n' : ' ');
        }
    }
}
*/

/*

#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
#define ALL(x) (x).begin(),(x).end()
#define RREP(i, a, n) for (int i = (a); i >= (b); --i)

int N, M;
int main() {
  cin >> N >> M;
  //vector<int> P;
  //REP (i, 1, N+1) P.push_back(i);
  vector<set<int>> twos(N);
  REP (i, 0, M) {
    int a, b; cin >> a >> b;
    twos.at(a-1).insert(b-1);
  }
  bool ans = true;
  vector<int> pm;
  REP (i, 0, N) {
    if (ans) {
      set<int> n = twos.at(i);
      if (n.size() <= 0) continue;
      else {
        unsigned int idx = distance(pm.begin(), lower_bound(ALL(pm), i));
        pm.insert(pm.begin() + idx, );
        FORE (x, n) {
          if(twos.at(x).count(i) >= 1) {
            ans = false;
            break;
          }
          unsigned int idx = distance(pm.begin(), lower_bound(ALL(pm), x));

        }
      }
    }
  }
  REP (i, 0, )

  if(!ans) cout << -1 << endl;

}
*/