#include <bits/stdc++.h>
using namespace std;

/* 再帰の練習 */

// AからBまでの総和を求める
int sum (int a, int b) {
  // AをBに一つずつ近づける
  // AとBが同じになったらBを返して終わる

  // ベースケース
  if (a == b) {
    return b;
  }
  // 再帰
  return a + sum(a+1, b);
}

// 配列の要素の総和
int array_sum (vector<int> v, int i) {
  // 配列のインデックスを一つずつ減らす
  // インデックスが0になったらat(0)のデータを返す

  --i;
  // ベースケース
  if (i == 0) {
    return v.at(0);
  }
  // 再帰
  return v.at(i) + array_sum(v, i);
}
/*
// 上記は引数が2つになってしまうため、補助関数とする
// アプローチは違うが上記のものでも間違いではない
// 基本概念 → 再帰で累積していく数（関数）＋再帰の現時点での位置の累積する数
// 　　　　　　int s(array_sum_sub)   + data.at(i)
int array_sum_sub (vector<int> &data, int i) {
  if (i == data.size()) return 0;
  int s = array_sum_sub(data, i+1);
  return data.at(i) + s;
}
int array_sum (vector<int> &data) {
  return array_sum_sub (data, 0);
}
*/

// 素数の判定
// 補助関数は約数が出るかどうかを確認する
bool is_prime_sub (int n, int i) {
  // n%i==0の時、約数があるとする
  // しかし、n==iが先に来た場合は素数である（約数はない）
  // nの数を一つずつ増やし、約数が来るか素数が来るかを判定する
  if (n == i) return true;
  else if (n % i == 0) return false;
  // ここでi++にすると加算される前に再帰関数が走るので抜け出せなくなる
  // 必ず++iにすること
  return is_prime_sub(n, ++i);
}
bool is_prime (int n) {
  // n = 1は素数ではない
  if (n == 1) return false;
  // n = 2は素数
  else if (n == 2) return true;
  else return is_prime_sub(n, 2);
}

// 配列逆操作
vector<int> reverse_array_sub (vector<int> &data, int i) {
  if (data.size() == i) {
    vector<int> empty_data(0);
    return empty_data;
  }
  // その後もiを使用する場合、++i/--iは使用できない
  vector<int> rev_data = reverse_array_sub(data, i+1);
  rev_data.push_back(data.at(i));
  return rev_data;
}
vector<int> reverse_array(vector<int> &data) {
  return reverse_array_sub(data, 0);
}

int main() {
  // 総和
  cout << sum(2, 5) << endl;
  // 配列の総和
  vector<int> v = {5, 6, 9, 7, 8};
  cout << array_sum(v, v.size()) << endl;
  // 素数判定
  cout << is_prime(1) << endl;
  cout << is_prime(2) << endl;
  cout << is_prime(3) << endl;
  cout << is_prime(4) << endl;
  cout << is_prime(5) << endl;
  cout << is_prime(13) << endl;
  cout << is_prime(37) << endl;
  cout << is_prime(45) << endl;
  // 配列逆操作
  vector<int> rev = reverse_array(v);
  for (auto x: rev) cout << x << " ";
  cout << endl;
}