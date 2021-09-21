#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
int main() {
  vector<string> str(3);
  cin >> str.at(0) >> str.at(1) >> str.at(2);
  string n;
  cin >> n;
  REP (i, n.size()) {
    cout << str.at((int)(n.at(i) - '1'));
  }
  cout << endl;
}