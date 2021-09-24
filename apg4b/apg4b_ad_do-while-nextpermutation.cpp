#include <bits/stdc++.h>
using namespace std;

/* Do-While文 */
/* Doを実行してからWhileの条件文を確認する→最低でも１度はDoを実行する */
/* next_permutationを使用するのによく使われる */
/* next_permutation関数 */
/* 順列を列挙する関数 */
/* {1,2,3}とあった場合、{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}と列挙していく */
/* 該当する順列がなくなった場合（{3,2,1}の次はない）next_permutaionがfalseになるので抜けるという仕組み */
/* 計算量はO(N!)めちゃくちゃ大きいので注意 */
/* 逆演算関数のprev_permutaionもある */

int main() {
  vector<int> v = { 2, 1, 3 };
  sort(v.begin(), v.end());
  do {
    // 1行で今の並び方を出力
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
  } while (next_permutation(v.begin(), v.end()));
}
