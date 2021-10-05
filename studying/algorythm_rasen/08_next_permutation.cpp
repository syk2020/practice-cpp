#include <bits/stdc++.h>
using namespace std;

/* 順列全探索の練習 */
/* bit全探索よりはまだわかりやすい */

int N, A[12][12], perm[12], ans = INT_MAX;
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) cin >> A[i][j];
    perm[i] = i;
  }

  do {
    int sum = 0;
    for (int i = 0; i < N-1; ++i) sum += A[perm[i]][perm[i+1]];
    ans = min(ans, sum);
  } while (next_permutation(perm, perm+N));

  cout << ans << endl;
  return 0;
}