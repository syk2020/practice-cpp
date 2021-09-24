#include <bits/stdc++.h>
using namespace std;

/* 難しいので途中まで */

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

// 変数名を読み取りイコールを読み飛ばす
string read_name() {

}

// int式の項を1つ読み取る。
// 数字ならその値を返し、そうでないなら変数として解釈し変数の値を返す
// var_int : intの変数を保持するmap
int read_int(map<string, int> &var_int) {

}

// int式全体を読み取って計算する
// var_int : intの変数を保持するmap
int calc_int(map<string, int> &var_int) {

}

// vec値を読み取る
// 最初の"["は読み取ってある前提であることに注意
// var_int : intの変数を保持するmap
vector<int> read_vec_val(map<string, int> &var_int) {

}

// vec式の項を1つ読み取る
// vec値ならその値を返し、そうでないなら変数として解釈し変数の値を返す
// var_int : intの変数を保持するmap
// var_vec : vecの変数を保持するmap
vector<int> read_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec) {

}

// vec式全体を読み取って計算する
// var_int : intの変数を保持するmap
// var_vec : vecの変数を保持するmap
// vector<int> calc_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec)

vector<int> calc_vec(vector<int> &A, vector<int> &B, string op) {
  vector<int> result;
  for (int i = 0; i < A.size(); ++i) {
    if (op == "+") result.push_back(A.at(i) + B.at(i));
    else result.push_back(A.at(i) - B.at(i));
  }
  return result;
}

int main () {
  map<string, int> int_map;
  map<string, vector<int>> vec_map;
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    if (s == "int") {
      string name = readname;
    }
  }
}