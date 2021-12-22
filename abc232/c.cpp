#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define ALL(x) (x).begin(),(x).end()

/* 時間切れ。順列全探索でいけるっぽい */
/* 間が空きすぎて順列全探索も忘れている。いかん */

int main() {
  int N, M, a, b; cin >> N >> M;
  vector X(N, vector<bool>(N)), Y(N, vector<bool>(N));
  REP (i, 0, M) {
    cin >> a >> b; a--, b--;
    X.at(a).at(b) = X.at(b).at(a) = true;
  }
  REP (i, 0, M) {
    cin >> a >> b; a--, b--;
    Y.at(a).at(b) = Y.at(b).at(a) = true;
  }

  vector<int> P(N);
  // Pに0からNまでの数値を代入する
  // next_permutation向けのこんな関数があったなんて
  iota(ALL(P), 0);

  // P->ボールの位置を入れ替える組み合わせパターン
  // 全ての順列を確認、一つもfalseにならない組み合わせがあれば同じおもちゃといえる

  bool OK;
  do {
    OK = true;
    REP (i, 0, N) {
      REP (j, 0, N) {
        if (X.at(i).at(j) != Y.at(P.at(i)).at(P.at(j))) OK = false;
      }
    }
    if (OK) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(ALL(P)));
  cout << "No" << endl;
}


/*
// 最初の実装
// 1つだけWAが出ちゃった。何でだ〜

int N, M;
int ab0[10], ab1[10];
int toy0[30], toy1[30];

int main() {
  cin >> N >> M; int a, b;
  REP (i, 0, M) {
    cin >> a >> b; ab0[a]++, ab0[b]++; 
  }
  REP (i, 0, M) {
    cin >> a >> b; ab1[a]++, ab1[b]++; 
  }
  REP (i, 0, N+1) {
    toy0[ab0[i]]++, toy1[ab1[i]]++;
  }
  bool frag = true;
  REP (i, 0, N+1) {
    if (toy0[i] != toy1[i]) {
      frag = false; break;
    }
  }
  cout << (frag ? "Yes" : "No") << endl;
  
}
*/