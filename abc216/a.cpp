#include <bits/stdc++.h>
using namespace std;
int main() {
  double xy;
  cin >> xy;
  int x, y;
  x = xy;
  y = xy * 10 - x * 10;
  cout << x;
  if (y <= 2) cout << '-';
  else if(y > 6) cout << '+';
  cout << endl;
}