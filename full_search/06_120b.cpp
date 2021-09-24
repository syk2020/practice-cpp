#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc120/tasks/abc120_b

int main() {
  int A, B, K; cin >> A >> B >> K;
  // どちらも割り切れる数なので最初の数値はAかBの小さい方で良い
  // ※最初maxで書いてしまった。ACにはなるし計算量も微々たるものだけどminに直しておく
  int len = min(A, B);
  vector<int> div;
  // K番目に大きいものを出力する必要があるので、並び順も大きい順に検索していく
  for (int i = len; i >= 1; --i) {
    if (A % i == 0 && B % i == 0) div.push_back(i);
  }
  cout << div.at(K-1) << endl;
}