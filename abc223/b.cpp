#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define ALL(x) (x).begin(),(x).end()

string S;

int main() {
  cin >> S; int len = S.size();
  S += S;
  vector<string> dict;
  REP (i, 0, len) {
    dict.push_back(S.substr(i, len));
  }
  sort(ALL(dict));
  cout << dict.at(0) << endl;
  cout << dict.at(len-1) << endl;
  return 0;
}