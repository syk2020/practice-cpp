#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string ar[n][2];
  for (int i = 0; i < n; i++) {
    cin >> ar[i][0] >> ar[i][1];
  }
  bool br = false;
  for (int i = 0; i < n; i++) {
  	string test0 = ar[i][0];
  	string test1 = ar[i][1];
    for (int j = i + 1; j < n; j++) {
      if (test0 == ar[j][0]) {
        if(test1 == ar[j][1]) {
          cout << "Yes" << endl;
          br = true;
          break;
        }
      }
    }
    if (br) break;
  }
  if (!br) cout << "No" << endl;
  /*

  // わざわざboolで判定してなくても、returnしてしまうでよかったかな

  for (int i = 0; i < n; i++) cin >> ar[i][0] >> ar[i][1];
  for (int i = 0; i < n; i++) {
  	string a = ar[i][0], b = ar[i][1];
    for (int j = i + 1; j < n; j++) {
      if (a == ar[j][0] && b == ar[j][1]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
  */

}