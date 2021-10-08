#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_A

/* 再帰の問題 */
/* ビット探索よりこちらの方が計算量が少ない→場合による。Nが少なければの場合かな */

int N, A[29];
int Q, M, i;

// int M がA[i]で作れるかどうか
// なのでiがNより大きくなった時点でおしまい
int solve(int i, int M) {
  if (M == 0) return 1;
  if (i >= N) return 0;
  // solve(i+1, M) -> A[i]を使用しなかった場合
  // solve(i+1, M - A[i]) -> A[i]を使用した場合
  int res = solve(i+1, M) || solve(i+1, M-A[i]);
  // 上記のどちらかで1を返し続ければ最終的には1になる
  return res;
}

int main() {
  cin >> N;
  REP (i, 0, N) cin >> A[i];
  cin >> Q;
  REP (i, 0, Q) {
    cin >> M;
    cout << (solve(0, M) ? "yes" : "no") << endl;
  }
  return 0;
}

// bit全探索でいくと最後の問題がTLEになってしまう
/*
int N, Q;
vector<int> A, M;
int main() {
  cin >> N;
  REP (i, 0, N) {
    int n; cin >> n;
    A.push_back(n);
  }
  cin >> Q;
  REP (i, 0, Q) {
    int q; cin >> q;
    M.push_back(q);
  }
  vector<bool> ans(Q, false);
  REP (i, 0, Q) {
    REP (bit, 0, 1 << N) {
      int cnt = 0;
      REP (j, 0, N) {
        if (bit & 1 << j) cnt += A.at(j);
      }
      if (cnt == M.at(i)) {
        ans.at(i) = true;
        break;
      }
    }
    if (ans.at(i)) continue;
  }
  REP (i, 0, N) cout << (ans.at(i) ? "yes" : "no") << endl; 
}
*/