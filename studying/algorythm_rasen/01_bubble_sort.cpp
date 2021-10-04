#include <bits/stdc++.h>
using namespace std;

int N, A[10009];
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i], cout << A[i] << " ";
  cout << endl;

  // 最初から、小さい順にソートしていく
  for (int i = 0; i < N - 1; ++i) {
    // i番目の繰り返し時には、後ろからi個分はすでにソートが完了（大きい順に並んでいる）している
    for (int j = 0; j < N - (i+1); ++j) {
      if (A[j] > A[j+1]) swap(A[j], A[j+1]);
    }
    // 変化そのまま表示
    for (int k = 0; k < N; ++k) cout << A[k] << " ";
    cout << endl;
  }
  //for (int i = 0; i < N; ++i) cout << A[i] << endl;
  return 0;
}