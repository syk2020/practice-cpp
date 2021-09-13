#include <bits/stdc++.h>
using namespace std;

bool is_odd (int i) {
  return ((i%2) == 1);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a.at(i);
  }
  int ans = 0;
  while (1) {
    if (count_if(a.begin(), a.end(), is_odd) == 0) {
      for (int i = 0; i < a.size(); ++i) a.at(i) /= 2;
      ++ans;
    } else break;
  }
  cout << ans << endl;
}

/*
18行め、a.size()でエラーが出ていたので、nに修正するとベター
count_ifと自作関数is_oddがとても役に立った

bool is_odd (int i) {
  return ((i%2) == 1);
}
-> 自作関数の場合、処理が１行で終わっても{}を外すことはできない

count_if(a.begin(), a.end(), is_odd)
-> is_oddで奇数なら trueを返すようにしているので、条件としては０の時のみansを増やす
　　args3 で引数として自動にvector aの要素が入ることに注意

*/