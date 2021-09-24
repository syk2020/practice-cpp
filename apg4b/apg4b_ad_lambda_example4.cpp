#include <bits/stdc++.h>
using namespace std;

/* 実際のラムダ式使用例 */
/* ソート関数のみ使用して降順ソートを作る */

int main() {
  vector<int> v = { 2, 3, 1 };
  // 大きい順にソートさせる比較関数
  auto comp = [](int a, int b) { return a > b; };
  sort(v.begin(), v.end(), comp);

  cout << v[0] << endl; // v は {3, 2, 1}となっている

  // 直接渡すことも可能
  // sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
}
