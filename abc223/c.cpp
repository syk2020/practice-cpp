#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)

/* 終了直後にエラー把握して20分後にはACした。泣ける */
/* 敗因は速度*時間なのに、導火線iが全て消えるまでの時間*時間で計算していた */
/* できてたよ〜！本来なら余裕でできてたのに */
/* 速度キライ……つらたん */

int N;
int main() {
  cout << fixed << setprecision(6);
  cin >> N;
  vector<pair<double, double>> fuse;
  // 左端から火をつけて燃やし終わるトータルの時間を計算
  double tsec = 0;
  REP (i, 0, N) {
    double a, b; cin >> a >> b;
    fuse.push_back(make_pair(a, b));
    // ここでは燃やし終わる時間なので距離/速度
    tsec += a / b;
  }
  // 両端から燃やしてぶつかるよう、トータル/2を計算
  tsec /= 2;

  double ans = 0;
  REP (i, 0, N) {
    // ここをdoubleにしておく必要がある
    double a = fuse.at(i).first, b = fuse.at(i).second;
    // 読み込み時はintでもOKだが、tsecの計算時には
    // tsec += (double)a / (double)b;
    // とする必要がある（この時、ちょっとだけメモリの節約にもなる）
    if (tsec - a / b > 0) {
      ans += a;
      // 秒数を燃やし尽くした時間で引いていく
      tsec -= a / b;
    } else {
      // 燃える距離を計算する
      // 速度*秒数
      // 速度はこの場合bとなる（１秒間に燃える速度なので）
      ans += b * tsec;
      break;
    }
  }
  cout << ans << endl;
}

/*
int N;
int main() {
  cout << fixed << setprecision(6);
  cin >> N;
  vector<pair<int, int>> fuse;
  double tsec = 0;
  REP (i, 0, N) {
    int a, b; cin >> a >> b;
    fuse.push_back(make_pair(a, b));
    tsec += (double)a / (double)b;
  }
  tsec /= 2;
  // unsigned int idx = distance(sec.begin(), lower_bound(ALL(sec), tsec));

  double ans = 0;
  REP (i, 0, N) {
    int a = fuse.at(i).first, b = fuse.at(i).second;
    if (tsec - a / b > 0) {
      ans += a;
      tsec -= a / b;
    } else {
      ans += b * tsec;
      break;
    }
  }
  cout << ans << endl;
}
*/

/*
int N;
int main() {
  cout << fixed << setprecision(10);
  cin >> N;
  vector<pair<double, double>> fuse;
  vector<double> sec;
  double tsec = 0;
  REP (i, 0, N) {
    double a, b; cin >> a >> b;
    fuse.push_back(make_pair(a, b));
    tsec += a / b;
    sec.push_back(tsec);
  }
  tsec /= 2;
  auto it = lower_bound(ALL(sec), tsec);
  FORE (x, sec) cout << x << endl;
  cout << *it << endl;
  
  double sumsec = 0, ans = 0;
  REP (i, 0, N) {
    if (sec < sumsec + fuse.at(i).first / fuse.at(i).second) {
      cout << "speed: " << (fuse.at(i).first / fuse.at(i).second) << endl;
      cout << "time : " << (sec - sumsec) << endl;

      //ans += (len - sumL);
      ans += (fuse.at(i).first / fuse.at(i).second) / (sec - sumsec);
      break;
    } else if (sec == sumsec + fuse.at(i).first / fuse.at(i).second) {
      ans += fuse.at(i).first;
      break;
    } else {
      sumsec += fuse.at(i).first / fuse.at(i).second;
      ans += fuse.at(i).first;
      cout << "sumsec: " << sumsec << endl;
      cout << "ans : " << ans << endl;
    }
  }
  cout << ans << endl;
}
*/