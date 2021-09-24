#include <bits/stdc++.h>
using namespace std;

/* 最小値を比較する変数にはINT_MAXを、最大値を比較する変数にはINT_MINを代入すること */
/* 逆にするとforで何も変わらず-1が出力されるというお粗末な結果に */

int main() {
  vector<int> abc(3);
  for (auto &v : abc) cin >> v;
  int minx = INT_MAX, maxx = INT_MIN;
  for (auto v : abc) {
    minx = min(minx, v);
    maxx = max(maxx, v);
  }
  cout << maxx - minx << endl;
}
