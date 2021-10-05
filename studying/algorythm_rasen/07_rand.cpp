#include <bits/stdc++.h>
using namespace std;

/* 乱数による近似解を出す、モンテカルロ法 */
/* ここでは円周率の近似解を出す */

const int NUMBER_OF_SAMPLES = 100;
int main() {
  // seed初期化、ランダム化させる
  srand((unsigned) time(NULL));
  int cnt = 0;
  for (int i = 0; i < NUMBER_OF_SAMPLES; ++i) {
    // 32768 -> VisualStudioの乱数が32767までしか発生しないので合わせている
    double px = 1.0 * (rand() % 32768 + 0.5) / 32768.0;
    double py = 1.0 * (rand() % 32768 + 0.5) / 32768.0;
    // x^2+Y^2 = 1 という円の公式を使用して、その中に収まる場合のみカウントを取る
    if (px * px + py * py <= 1.0) cnt++;
  }
  cout << "PI = " << cnt / NUMBER_OF_SAMPLES << endl;
  return 0;
}