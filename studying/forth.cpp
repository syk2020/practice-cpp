#include <bits/stdc++.h>
using namespace std;
int main() {
  // 20. assert
  // ランタイムエラーを起こす関数
  // デバッグに使えるらしい
  int N, X, cnt, ar[10000];
  cin >> N >> X;
  for (int i = 1; i <= N; i++) cin >> ar[i];
  // N > 10000 の場合実行時間が間に合わない（TLE する）のでランタイムエラーを起こすようにする
  assert(N <= 10000);
  for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
          if (ar[i] + ar[j] == X) cnt++;
      }
  }
  cout << cnt << endl;

  // 21. count
  // 配列やvectorである要素xがいくつ含まれているかを返す
  // すごい便利ってかこれだよ知りたかったの
  int cntar[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 1};
  cout << count(cntar, cntar+10, 1) << endl; // 4
  cout << count(cntar, cntar+10, 2) << endl; // 3

  // 22. find
  // 配列やvectorである要素xが含まれるか、含まれている場合は最初どこにあるかを返す
  // 返すのはイテレーター、慣れればいいかもしれないけど最初ちょっと難しい
  int finar[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 1};
  auto *it = find(finar, finar+10, 2);
  cout << *it << endl; // 2
  // 配列の何番目かを知りたいときは、配列で引くといい
  int indexnum = find(finar, finar+10, 2) - finar;
  cout << indexnum << endl; // 1
  // 存在しない場合は　配列のsize()（この場合10）と等しくなる
  int indexnone = find(finar, finar+10, 5) - finar;
  if (indexnone == 10) cout << "NONE" << endl; // NONE


  // 23. next_permutation
  // 順列を生成する
  int np[3] = {1, 2, 3};
  do {
    for (int i = 0; i < 6; i++) {
      if (i) cout << ",";
      cout << np[i];
    }
    cout << endl;
  } while (next_permutation(np, np + 3));
  // 1,2,3
  // 1,3,2
  // 2,1,3
  // 2,3,1
  // 3,1,2
  // 3,2,1
  // -> 辞書順で順列をひたすら作り続ける
  // 頻繁に使わないけど自分で実装するより絶対早い
  // ただし次の順列を生成するのに計算量がO(n), 
  // 上記のソートしていてかつwhileで全て生成する場合は最大O(n!)なので注意

  // 24. __builtin_popcount
  // x を 2 進数表記したときに、1 であるビットの個数を出力する。
  long long bitx;
  cin >> bitx;
  cout << __builtin_popcountll(bitx) << endl; 
  // 5 -> 2(101), 6 -> 2(110), 7 -> 3(111), 8 -> 1(1000)
  // 多分この後のbitsetで使うのかな？？？

  // 25. bitset
  // ビット集合を表す。N桁の２進数
  // ビット演算をするのに使用
  bitset<8> bs8a(-105); // 10010111
  // reset -> 1から０へ
  bs8a.reset(0);        // 10010110
  bitset<8> bs8b(105);  // 01101001
  // set -> 0から１へ
  bs8b.set(2);          // 01101101
  cout << bs8b.count() << endl; // 5
  cout << bs8a[1] << endl; // 0
  // 活用方法がようわからんので確認
}