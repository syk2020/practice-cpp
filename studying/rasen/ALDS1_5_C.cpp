#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
#define ALL(x) (x).begin(),(x).end()
#define RREP(i, a, n) for (int i = (a); i >= (b); --i)
using ll = long long;
const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_C

/* コッホ曲線 */
/* コッホ曲線はフラクタルの一種として知られています。フラクタルとは再帰的な構造を持つ図形のことで、以下のように再帰的な関数の呼び出しを用いて描画することができます。
与えられた線分 (p1, p2) を 3 等分する。
線分を 3等分する 2 点 s, t を頂点とする正三角形 (s,u,t) を作成する。
線分(p1,s)、線分 (s,u)、線分 (u, t)、線分(t, p2) に対して再帰的に同じ操作を繰り返す。 */

// 座標の構造体を作成する
struct Point { double x, y; };
int N;

void koch (Point a, Point b, int n) {
  if (n == 0) return;
  Point s,t,u;
  // ラジアンに変換
  double rad = M_PI * 60 / 180;

  s.x = (2*a.x + b.x) /3;
  s.y = (2*a.y + b.y) /3;
  t.x = (a.x + 2*b.x) /3;
  t.y = (a.y + 2*b.y) /3;
  /* 頂点uの求め方
  回転行列を使う（線形代数わからん）
  u.x = (t.x - s.x) * cos60° - (t.y - s.y) * sin60° + s.x;
  u.y = (t.x - s.x) * sin60° + (t.y - s.y) * cos60° + s.y;
  最後のs.x, s.yは0を原点とした計算をしているからなのはわかる

  Wikipedia回転行列（https://ja.wikipedia.org/wiki/%E5%9B%9E%E8%BB%A2%E8%A1%8C%E5%88%97#2%E6%AC%A1%E5%85%83%E3%81%AE%E5%9B%9E%E8%BB%A2%E8%A1%8C%E5%88%97）より
  なぜならば、原点中心に θ 回転して点 (x, y) が (x', y') に写るとすると、
  図形的考察または三角関数の加法定理より、x', y' は以下のように表されることが分かる。
  x' = x * cosθ - y * sinθ
  y' = x * sinθ + y * cosθ 

  θ -> 60°とする　cos, sinの引数はラジアンなので換算し直す
  */
  u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
  u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;

  n--;
  // スタートから最初の線分sまで
  koch(a, s, n);
  cout << s.x << " " << s.y << endl;
  // 最初の線分sから頂点uまで
  koch(s, u, n);
  cout << u.x << " " << u.y << endl;
  // 頂点uから2つ目の線分tまで
  koch(u, t, n);
  cout << t.x << " " << t.y << endl;
  // 二つ目の線分tから最後まで
  koch(t, b, n);
}

int main() {
  cin >> N;
  Point a, b;
  a.x = 0.0, a.y = 0.0;
  b.x = 100.0, b.y = 0.0;
  // 0.0001以下の誤差は無視するとあるので、小数点以下5桁以上を表示させる
  cout << fixed << setprecision(8);
  cout << a.x << " " << a.y << endl;
  koch(a, b, N);
  cout << b.x << " " << b.y << endl;
  return 0;
}