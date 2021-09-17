#include <bits/stdc++.h>
using namespace std;

/* priority_queueの使い道を知った私に死角はない Pt.2 */
/* とはいえ、もう少しwhile内の処理をうまく書ける気もする */

int main() {
  int n;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    pq.push(m);
  }
  int cnt = 0;
  int x = 0;
  while(!pq.empty()) {
    int mochi = pq.top();
    pq.pop();
    if (mochi == x) continue;
    else {
      x = mochi;
      ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}