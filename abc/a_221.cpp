#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc221/tasks/abc221_a

int main() {
  int A, B;
  cin >> A >> B;
  // ここでllにしておかないと多分表記がおかしくなるところが出てくる
  // それが原因でえらい時間を食ってしまった
  // もしくは cout << (int)pow(32, A-B) << endl;
  long long x = A == B ? 1 : pow(32, A-B);
  cout << x << endl;

  
  // この書き方はいいな
  // for (int i = b; i < a; i++)k *= 32;
	// cout << k << endl;
  
}