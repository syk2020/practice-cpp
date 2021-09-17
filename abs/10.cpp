#include <bits/stdc++.h>
using namespace std;

/* dreamerとeraserという被る文字列があるので、後ろから消していくとベター */
/* しかし泥臭く解いてしまった */
/* reverse()で逆回転させてから解くか〜考えつかなかった */
/* 後ろから、というのに気づけただけでもえらいぞわたし */

int main() {
  string s; cin >> s;
  int s_size = s.size();
  string ans = "NO";
  while (s_size >= 5) {
    string matcher = s.substr(s_size-5, 5);
    if (matcher == "dream" || matcher == "erase") {
      s.erase(s_size-5, 5);
      s_size = s.size();
      continue;
    }
    if (s_size >= 6) {
      matcher = s.substr(s_size-6, 6);
      if (matcher == "eraser") {
        s.erase(s_size-6, 6);
        s_size = s.size();
        continue;
      }
      if (s_size >= 7) {
        matcher = s.substr(s_size-7, 7);
        if (matcher == "dreamer") {
          s.erase(s_size-7, 7);
          s_size = s.size();
          continue;
        }
      }
    }
    break;
  }
  if (s_size == 0) ans = "YES";
  cout << ans << endl;
}

/*
// 公式解説
// Greedyアルゴリズムというらしい
string divide[4] = {"dreamer", "dream", "eraser", "erase"};
int main() {
  string s; cin >> s;

  // 全部逆さまにする
  reverse(s.begin(), s.end());
  for (int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());

  bool can = true;

  // ここで第３引数をなくし、ループを自動でカウントアップさせないようにする
  for (int i = 0; i < s.size();) {
    // 上記の文字列のどれかと一致したかどうかを判別する
    bool can2 = false;
    for (int j = 0; j < 4; ++j) {
      string d = divide[j];
      // どれかの文字列と一致するか確かめる
      if (s.substr(i, d.size()) == d) {
        can2 = true;
        // 一致した場合 i をd.size()ぶん押し上げる
        i += d.size();
        break;
      }
    }
    // ここでcan2がtrueになっていなかったら4つのうちのどれも分割できなかったということ
    if (!can2) {
      can = false;
      break;
    }
  }
  cout << (can ? "YES" : "NO") << endl;
}

*/