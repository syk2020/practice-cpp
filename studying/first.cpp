#include <bits/stdc++.h>
using namespace std;
int main() {
  // 1. 絶対値 abs (fabs) cmathをインクルードして使える
  double a, b;
  cin >> a >> b;
  printf("%.12lf\n", abs(a-b));
  
  // 2. 三角関数 sin, cos, tan, 例外 acos
  // 三角関数の引数は弧度法なので 度数/180*PIにする必要がある
  // PIは arccos(-1) で出る
  const double PI = acos(-1);
  double x;
  cin >> x;
  printf("%.12lf\n", sin(x / 180.0 * PI));
  printf("%.12lf\n", cos(x / 180.0 * PI));
  printf("%.12lf\n", tan(x / 180.0 * PI));

  // 3. 文字列 string, char stringをインクルードして使える
  string S, T;
  char ch;
  cin >> S >> T;
  cout << S << endl;
  // S[i] i番目の文字列
  // ただしi > S.size()-1の場合、Sには何の変更もされない
  // 0番目をzに変更
  S[0] = 'z';
  // SとTを連結
  S += T;
  // charも連結可能
  S += ch;
  // 文字列の長さ、整数型
  int sizeOfStr = S.size();
  // 文字列のうちl番目以降を返す
  string SsubstrL = S.substr(5);
  // 文字列のうちl番目からl+r-1番目までを返す
  // 先頭は0文字目となる
  // この例だと2文字目から4文字目までの3文字返す
  string SsubstrLR = S.substr(2, 3);

  // 例外
  // 各整数型の最大値を確認する
  // 2147483647
  cout << INT_MAX << endl; 
  // -2147483648
  cout << INT_MIN << endl;
  // 9223372036854775807
  cout << LONG_MAX << endl;
  // -9223372036854775808
  cout << LONG_MIN << endl;
  // 18446744073709551615
  cout << ULONG_MAX << endl;

  /* メモ */
  // ループでTLEにならないのは10^7ぐらいまで
  // 10^9 までが最大値になるならintでいけるが、それを3つ以上足し合わせるとllにする必要あり

}