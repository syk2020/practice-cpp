#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)

/* REP (k, names.at(i).size()) としたところ、第２引数がintではないとお叱りを受ける */
/* そうでなくてもタイムアウトしているのでダメだと思われる */

int main() {
  string X;  cin >> X;
  int N;  cin >> N;
  vector<string> names;
  REP (i, N) {
    string name;  cin >> name;
    names.push_back(name);
  }
  for (int h = N-1; h > 0; --h) {
    REP (i, h) {
      int maxsize = names.at(i).size();
      REP (k, maxsize) {
        bool flag = false;
        char a = names.at(i).at(k);
        char b = names.at(i+1).at(k);
        REP (j, 26) {
          if (X.at(j) != a && X.at(j) != b) continue;
          else if (X.at(j) == a && X.at(j) == b) continue;
          else if (X.at(j) == a && X.at(j) != b) {
            flag = true;
            break;
          } else {
            swap(names.at(i), names.at(i+1));
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
    }
  }
  REP (i, N) {
    cout << names.at(i) << endl;
  }
}

/*
// 方針その１　新しいソートを指定する比較関数を実装する
// きっとこれをやるのでは、と思ったけどやり方が怪しかったので避けてしまった。。。。
int main() {
    string X;
    cin >> X;
    vector<int> pos(26);
    for (int i = 0; i < 26; ++i) {
      // pos[i] -> 本来i番目のアルファベットが何番目に来るのか格納
        pos[X[i] - 'a'] = i;
    }
    int N;
    cin >> N;
    vector<string> S(N);
    // &s でSに格納していく
    for (string& s : S) cin >> s;
    // ラムダ関数でソート方法を指定する
    sort(begin(S), end(S), [&](const string& s, const string& t) {
        // 文字列の比較
        int len = min(size(s), size(t));
        for (int i = 0; i < len; ++i) {
            if (s[i] != t[i]) {
                return pos[s[i] - 'a'] < pos[t[i] - 'a'];  
            }
        }
        return size(s) < size(t);
    });
    for (const string& s : S) {
        cout << s << '\n';
    }
}

// 方針その２　名前を読み込むとき、文字列ではなく数字として読み込んでしまう 
int main() {
    string X;  cin >> X;
    // アルファベット順を配列に入れていく
    vector<int> pos(26);
    for (int i = 0; i < 26; ++i) {
        pos[X[i] - 'a'] = i;
    }
    int N;  cin >> N;
    vector<vector<int>> S(N);
    for (vector<int>& v : S) {
        string s;
        cin >> s;
        // 1文字ずつを数値変換した配列として格納
        for (const char c : s) {
            v.push_back(pos[c - 'a']);
        }
    }
    // 数値順なので、通常のソートが機能する
    sort(begin(S), end(S));
    for (const vector<int>& s : S) {
        for (const int x : s) {
            cout << X[x];
        }
        cout << '\n';
    }
    return 0;
}

// 方針２の方が好きだけど、１もできるようにしておきたい
// これがC問題で出るのはso hardだなー
*/