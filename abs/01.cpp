#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a % 2 == 1 && b % 2 == 1) cout << "Odd" << endl;
  else cout << "Even" << endl;
  // return 0; <- 忘れてる
}

/*
// 素直にかければ良かったよねえ。。。。。
// 難しく考えてしまうあるあるにすでにハマりかけている。。。。。
int main() {
    int a, b;
    cin >> a >> b;
    int c = a * b;
    if (c % 2 == 0) cout << "Even" << endl;
    else cout << "Odd" << endl;
}
*/