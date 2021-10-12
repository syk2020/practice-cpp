#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define ALL(x) (x).begin(),(x).end()
using ll = long long;

// https://atcoder.jp/contests/abc221/tasks/abc221_c

/* 差を最小にすれば良いのは知ってたんだけどうまいこと組み合わせができなくて */
/* そろそろC問題は素直に全探索でいけると */

int main() {
  int N, zero = 1; cin >> N;
  vector<int> nums;
  while (N > 0) {
    if (N % 10 == 0) zero *= 10;
    else nums.push_back(N % 10);
    N /= 10;
  }
  sort(ALL(nums));
  int ans = 0;
  do {
    for (int i = 1; i < nums.size(); ++i) {
      int a = 0, b = 0;
      for (int j = 0; j < i; ++j) a *= 10, a += nums.at(j);
      for (int j = i; j < nums.size(); ++j) b *= 10, b += nums.at(j);
      ans = max(ans, a*b);
    }
  } while (next_permutation(ALL(nums)));
  
  cout << ans * zero << endl;
}

/*
// 汗と涙と鼻水の結晶(WA)
int main() {
  int N, zero = 1; cin >> N;
  priority_queue<int> nums;
  while (N > 0) {
    if (N % 10 == 0) zero *= 10;
    else nums.push(N % 10);
    N /= 10;
  }

  bool odd = false;
  if (nums.size() % 2 == 1) {
    odd = true;
    nums.push(0);
  }

  int a, b;
  a = nums.top(); nums.pop();
  b = nums.top(); nums.pop();

  while (nums.size() > 1) {
    b *= 10; b += nums.top(); nums.pop();
    a *= 10; a += nums.top(); nums.pop();
  }

  ll ans = odd ? a * b * zero / 10 : a * b * zero;
  cout << (int)ans << endl;
}
*/