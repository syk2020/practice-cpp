#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)
#define ALL(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc222/tasks/abc222_c


int N, M;
vector<pair<int, int>> winNum;
vector<string> GCP;

// 勝ち負けのシステムは悪くなかった
// 最後のプラスにする分で分岐するとこまで思いつかなかった
int checkWin(char a, char b) {
  if (a == b) return -1;
  // 前者の勝ち->0, 後者の勝ち->1, こうすることによって[2*j+win]の結果が勝者（のインデックス）になる
  return ((a == 'G' && b == 'C') || (a == 'C' && b == 'P') || (a == 'P' && b == 'G')) ? 0 : 1;
}

// 全探索ということは気づけたけど結局ランク付の上手い方法が思いつかなくて挫折した感じ
// データ構造も思いついたし、道筋も悪くなかったから前進したと思おう。。。
// このぐらいはできるようになりたいな〜
int main() {
  cin >> N >> M;
  REP (i, 0, 2*N) {
    string s; cin >> s;
    GCP.push_back(s);
    winNum.push_back(make_pair(0, i));
  }
  REP (i, 0, M) {
    REP (j, 0, N) {
      // 0 からのカウント -> 2*0=0, 2*0-1=-1でインデックスとして不適当になってしまう
      // インデックスとして使いたい場合は　2*0=0, 2*0+1=1とすると良い
      pair<int, int> pl1 = winNum.at(2*j), pl2 = winNum.at(2*j+1);
      int win = checkWin(GCP.at(pl1.second).at(i), GCP.at(pl2.second).at(i));
      if (win == -1) continue;
      // 勝者の順位（winNumのfirst）を勝利数に応じて-1する
      // 勝ち以外は変動なし＆勝った時はランクが上がる＝数値が若くなるので、勝った時に-1する
      else winNum.at(2*j+win).first -= 1;
    }
    // １ラウンド終了ごとにソートをする
    // ランキング、プレイヤー番号で若い順にソートされる
    sort(ALL(winNum));
  }
  FORE (x, winNum) cout << x.second + 1 << endl;
}

// 悪戦苦闘した軌跡
/*
int N, M;
vector<pair<int, int>> winNum;
vector<string> GCP;

int checkWin(char a, char b) {
  if (a == b) return -1;
  return ((a == 'G' && b == 'C') || (a == 'C' && b == 'P') || (a == 'P' && b == 'G')) ? 0 : 1;
}

int main() {
  cin >> N >> M;
  REP (i, 0, 2*N) {
    string s; cin >> s;
    GCP.push_back(s);
    winNum.push_back(make_pair(0, i));
  }
  REP (i, 0, M) {
    REP (j, 0, N) {
      pair<int, int> pl1 = winNum.at(2*j-1), pl2 = winNum.at(2*j);
      int win = checkWin(GCP.at(pl1.second).at(i), GCP.at(pl2.second).at(i));
      if (win == -1) continue;
      else if (win) winNum.at(2*j).first += 1;
      else winNum.at(2*j - 1).first += 1;
    }
    sort(ALL(winNum));
  }
  FORE (x, winNum) cout << x.first << " " << x.second << endl;

}
*/

/*
  REP (i, 0, M) {
    REP (j, 0, M) {
      int ind = 0;
      bool ch1 = false, ch2 = false;
      char a, b;
      REP (k, ind, 2*N) {
        if(ch1 && ch2) break;
        if(!ch1) {
          if (winNum.at(k).second == M - j) {
            ch1 = true;
            a = GCP.at(winNum.at(k).first).at(i);
            continue;
          }
        } else {
            ch2 = true;
            b = GCP.at(winNum.at(k).first).at(i);
            ind = k;
            continue;
        }

      }
    }
  }
*/

/*
int main() {
  cin >> N >> M;
  REP (i, 0, 2*N) {
    string s; cin >> s;
    GCP.insert(s);
  }
  REP (i, 0, N) {
    char a, b;
    a = GCP.at(2*i - 1).at(0);
    b = GCP.at(2*i).at(0);
    int win = checkWin(a, b);
    if (win) {
      winNum.insert(make_pair(2*i - 1, 1));
      winNum.insert(make_pair(2*i, 0));
    } else {
      winNum.insert(make_pair(2*i - 1, 0));
      winNum.insert(make_pair(2*i, 1));
    }
  }
  REP (i, 1, M) {
    sort(ALL(winNum));
    REP (j, 0, N) {
      char a, b;
      a = GCP.at(winNum.at(2*j - 1).first).at(i);
      b = GCP.at(winNum.at(2*j).first).at(i);
      int win = checkWin(a, b);
      if (win) {
        winNum.insert(make_pair(2*i - 1, 1));
        winNum.insert(make_pair(2*i, 0));
      } else {
        winNum.insert(make_pair(2*i - 1, 0));
        winNum.insert(make_pair(2*i, 1));
      }
    }

  }
}*/