#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
  cin >> N;
  cout << (N >= 100 && N % 100 == 0 ? "Yes" : "No") << endl;
  return 0;
}