#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  map<int, int> modemap;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    if(modemap.count(a)) modemap.at(a) += 1;
    else modemap[a] = 1;
  }
  int modekey, modevalue = INT_MIN;
  // Keyの値が小さい順にループ
  for (auto p : modemap) {
    auto key = p.first;
    auto value = p.second;
    // key, valueを使う
    if (modevalue < value) {
      modekey = key;
      modevalue = value;
    }
  }
  cout << modekey << " " << modevalue << endl;
}

/*
// modekeyが初期化されてないと言われるので、なんでもいいから初期化しておくといいかも

// mapのforは下記の通りでも回せる
  for (int x : A) {
    if (max_cnt < cnt.at(x)) {
      max_cnt = cnt.at(x);
      ans = x;
    }
  }
*/