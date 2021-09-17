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

/*
// 集計処理になる模様
// よくよく考えれば重複が出ないsetで解く方が良かったなと今更

// バケット法による解
int main() {
    int N;
    int d[110];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> d[i];

    int num[110] = {0};  // バケット
    for (int i = 0; i < N; ++i) {
        num[d[i]]++;  // d[i] が 1 個増える
    }

    int res = 0;  // 答えを格納
    for (int i = 1; i <= 100; ++i) {  // 1 <= d[i] <= 100 なので 1 から 100 まで探索
        if (num[i]) {  // 0 より大きかったら
            ++res;
        }
    }
    cout << res << endl;
}

// std::set を用いた解
int main() {
    int N;
    int d[110];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> d[i];

    set<int> values; // insert するときに重複を取り除いてくれます
    for (int i = 0; i < N; ++i) {
        values.insert(d[i]); // 挿入します
    }

    // set のサイズを出力します
    cout << values.size() << endl;
}
*/