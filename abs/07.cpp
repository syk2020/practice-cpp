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