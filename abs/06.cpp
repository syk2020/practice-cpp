#include <bits/stdc++.h>
using namespace std;

/* priority_queueの使い道を知った私に死角はない */

int main() {
  int n, A = 0, B = 0;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    pq.push(c);
  }
  int counter = 0;
  while(!pq.empty()) {
    int card = pq.top();
    if (counter % 2 == 0) A += card;
    else B += card;
    pq.pop();
    ++counter;
  }
  cout << A - B << endl;
  return 0;
}

/*
// これ、どっちが計算量低くなるのか要確認
// でもpushのたびに演算するより後からsortかけた方がきっと早い
int main() {
    int N;
    int a[110];  // 最大 100 個ですが余裕をもたせます
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];

    sort(a, a + N, greater<int>());  // a[0:N] を大きい順にソート
    int Alice = 0;
    int Bob = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) { // Alice のターン
            Alice += a[i];
        }
        else { // Bob のターン
            Bob += a[i];
        }
    }
    cout << Alice - Bob << endl;
}
*/