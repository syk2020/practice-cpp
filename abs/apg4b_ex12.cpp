#include <bits/stdc++.h>
using namespace std;

/* なんとなくうまくいった気がするので保存 */

int main() {
  string S; cin >> S;

  // ここにプログラムを追記
  int cntplus = 1, cntminus = 0, len = S.size();
  for (int i = 0; i < len; i++) {
    if (i%2 == 1) {
      if(S.at(i) == '+') ++cntplus;
      else ++cntminus;
    }
  }
  cout << cntplus - cntminus << endl;   
}
