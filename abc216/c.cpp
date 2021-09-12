#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<char> v;
  while (n > 0) {    
    if (n % 2 == 0) {
      v.insert(v.begin(), 'B');
      n /= 2;
    } else {
      v.insert(v.begin(), 'A');
      n -= 1;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
}