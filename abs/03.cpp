#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> ch(3);
  cin >> ch.at(0) >> ch.at(1) >> ch.at(2);
  cout << count(ch.begin(), ch.end(), '1') << endl;
}
// return忘れるなあ