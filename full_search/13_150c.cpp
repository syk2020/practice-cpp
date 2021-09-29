#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
#define ALL(x) (x).begin(),(x).end()

int N;

bool checker (vector<int> A, vector<int> B) {
  int len = A.size();
  REP (i, 0, len) {
    if (A.at(i) != B.at(i)) return false;
    else continue;
  }
  return true;
}

int main() {
  cin >> N;
  vector<int> P(N), Q(N);
  FORE (x, P) cin >> x;
  FORE (x, Q) cin >> x;
  vector<int> permutation;
  REP (i, 1, N+1) {
    permutation.push_back(i);
  }
  int a, b, cnt = 0;
  do {
    ++cnt;
    if (checker(permutation, P)) a = cnt;
    if (checker(permutation, Q)) b = cnt;
  } while (next_permutation(ALL(permutation)));
  cout << abs(a-b) << endl;
}