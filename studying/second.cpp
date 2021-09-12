#include <bits/stdc++.h>
using namespace std;
int main() {

  // 4.　最大値(max)・最小値(min) algorithmをインクルードして使える
  // min(a,b) で小さい方を返します
  cout << min(5, 9) << endl;
  // 複数個比較したいときはmin({a1, a2, a3....})とする
  cout << min({0, 2, -4}) << endl;
  // maxも同様
  cout << max(9, 0) << endl;
  cout << max({19, 32, 0}) << endl;
  // int型の限界値 -> 2,147,483,647 = 2^31-1(負の符号も入るので範囲としては2^32)
  // 10^8までは扱える
  // 配列の最小値の出し方
  int N, c[100009], minx = 2147483647;
  cin >> N;
  for (int i = 1; i<=N; i++) cin >> c[i];
  for (int i = 1; i<=N; i++) minx = min(minx, c[i]);
  cout << minx << endl;
  // イテレーターを返すこともできる（要確認）
  // イテレーターを返す場合は最初に*が必要
  cout << *min_element(c+1, c+N+1) << endl;
  
  // 5. 二つの値を交換する swap iostream をインクルードして使える
  // 知らない関数だ
  int a, b;
  cin >> a >> b;
  swap(a, b);
  cout << a << " " << b << endl;
  // バブルソートがめちゃくちゃ簡単に実装できる
  // バブルソート→最初から二つ数値を確認、大きいものを後ろへ
  // 大きいものが最後（N2-i番目）に来るので、そこは不動
  // N2-i=0になるまで実施、すると小さい順にソートされている
  int N2, c2[1009];
  cin >> N2;
  for (int i = 1; i <= N2; i++) cin >> c2[i];
  for (int i = 1; i <= N2; i++) {
    for (int j = 1; j <= N2-i; j++) {
      if (c2[j] > c2[j+1]) {
        swap(c2[j], c[j+1]);
      }
    }
  }
  for (int i = 1; i <= N2; i++) cout << c[i] << endl;

  // 6. 最大公約数 __gcd algorithmをインクルードして使える
  // ちなみに Greatest Common Divisor （最大公約数）の頭文字
  // 最小公倍数はLeast Common Multiple 
  // O(log a)で高速
  int d, e;
  cin >> d >> e;
  cout << __gcd(d, e) << endl;
  // 最小公倍数は、一つを最大公約数で割った数にもう一つをかければ出る
  cout << d / __gcd(d, e) * e << endl;

  // 7. 乱数 rand ctime をインクルードして使える
  // 基本の２種類
  // srand((unsigned)time(NULL)) -> 種の設定
  // 時間によって変わるので、これを書くと実行ごとに結果が変わる
  srand((unsigned)time(NULL));
  // rand() -> 0 >= x >= 2^31-1(int正の限界値)までの乱数を生成
  if (rand() % 10 <= 8) cout << "Yay!" << endl;
  else cout << "Oh, No" << endl;
  // 精度の高い乱数を発生させたい場合は
  // #include <random>として、std::mt19937 mtを使用する（要確認）

  // 8. 時間計測 clock ctime をインクルードして使える
  // clock() -> プログラム実行から何単位時間経過したかを整数で返します
  // CLOCKS_PRE_SEC -> 定数。1秒が何単位時間になるか（環境によって異なる）
  int ti = clock();
  for (int i = 1; i <= 100000; i++) cout << i << endl;
  printf("Execution Time: %.4lf sec \n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);

  // 9. 逆順に並べ替え reverse algorithmをインクルードして使える
  // 計算量 O(n)
  // arr を適当な配列とします
  // reverse(arr+l, arr+r) -> arr[l] から arr[r] までを逆順に並び替えます
  int arr[9] = {2, 4, 5, 7, 8, 9, 1, 6, 3};
  reverse(arr+2, arr+7);
  for (int i = 0; i < 9; i++) cout << arr[i] << endl;
  // reverse(arr, arr+N) -> arr[0] から arr[N] までを逆順に並べ替えます
  reverse(arr, arr+5);
  for (int i = 0; i < 9; i++) cout << arr[i] << endl;
  // string型でも使用可能
  // 単純に逆順で　str.begin(), str.end() とする
  string str = "0123456789";
  reverse(str.begin(), str.end());

  // 10. 並べ替え sort algorithm, greaterをつけるときはfunctionalをインクルードして使える
  // 計算量はO(n log n)
  // 書き方はreverseとほぼ同じ、stringも使える
  // 基本的には小さい順に並べる
  int array[9] = {2, 4, 5, 7, 8, 9, 1, 6, 3};
  sort(array+1, array+5);
  // sort(array, array+5, greater<T>()) -> 範囲内を大きい順に並べる
  sort(array, array+4, greater<int>());

}