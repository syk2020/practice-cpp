#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); ++i)
#define FORE(i, a) for (auto &i : a)

// https://atcoder.jp/contests/abc147/tasks/abc147_c

/* 公式解説を見る感じ、証言を正直・不安定に分けたり、
　　誰がどの人に対してとどう証言してるかについて分けて配列格納していた */
/*  ACまですごい時間を浪費した。原因はどこで何を計算するかを把握していなかったこと */
/*  ↑よくある失敗なので気をつける！ */


int N, A;
// 15の長さを持つ配列が入るvectorを2つ作っている
vector<int> t[15], f[15];

int cnt(int x) {
    if (x==0) return 0;
    return cnt(x >> 1) + (x & 1);
}

int main() {
  cin >> N;
  REP (i, 0, N) {
    cin >> A;
    REP (j, 0, A) {
      int X, Y; cin >> X >> Y; --X;
      if(Y) t[i].push_back(X);
      else f[i].push_back(X);
    }
  }
  
  int ans = 0;
  REP (bits, 1, 1 << N) {
    bool ok = true;

    REP (i, 0, N) {
      if (!(bits & (1 << i))) continue;
      if (ok) {
        FORE (truthy, t[i]) {
          if (!(bits & (1 << truthy))) {
            ok = false;
            break;
          }
        }
        FORE (falsy, f[i]) {
          if (bits & (1 << falsy)) {
            ok = false;
            break;
          }
        }
      } else break;
    }
    // 今回は正直者の証言者をカウントするので、全ての証言者の検証が終わった段階でカウントを取る
    if(ok) ans = max(ans, cnt(bits));
  }
  cout << ans << endl;
}


/*
// 思考の方向性は悪くないと思うけどうまく行かず。
int main() {
  int N; cin >> N;
  vector<vector<pair<int, int>>> people;
  REP (i, 0, N) {
    // 人i毎に証言を取得
    int p; cin >> p;
    vector<pair<int, int>> words;
    REP (j, 0, p) {
      int a, b; cin >> a >> b;
      // 人x(ij)はデクリメントして後から探索しやすくすること
      pair<int, int> pa = make_pair(--a, b);
      // pairを格納していく
      words.push_back(pa); 
    }
    // 一人の証言が終わったらpeopleに格納
    people.push_back(words);
  }
  // bit全探索
  // Nのビット列で全探索
  int ans = 0;
  REP (bit, 0, 1 << N) {
    // ビット列により正直＝1と仮定された人の証言を正しいとし、ビット列が呼応しているか確認
    int maxmember = 0;
    REP (j, 0, N) {
      bool ok = true;
      int numwords = people.at(j).size();
      REP (k, 0, numwords) {
        // 呼応していない場合、チェッカーフラグをFにする
        pair<int, int> checkpa = people.at(j).at(k);
        // 調べたいフラグを1までおろす
        // うまく行かず
        // if ((bit >> checkpa.first+1 & 1) ^ checkpa.second) ok = false;
        
        if (checkpa.second) {
            if (!(bit & (1 << checkpa.first))) ok = false;
        } else {
            if (bit ^ (1 << checkpa.first)) ok = false;
        }
      }
      // チェッカーがTのままなら最大人数としてカウント
      if (ok) ++maxmember;
    }
    // あるビットでの探索終了時、証言者フラグがそれまでの最大人数より大きければ証言者フラグの数を最大人数に変更
    chmax(ans, maxmember);
  }
  cout << ans << endl;
}
*/

/*
公式の回答はもっと何書いてあるかわかんない
#include <bits/stdc++.h>
using namespace std;

int N;
int A[20];
int x[20][20];
int y[20][20];

// -> bitsの１の数を数え上げてるっぽい
int counter(int x) {
    if(x == 0) return 0;
    // 1個ずつ右シフトするx >> 1
    // 右シフトした結果、末尾が1なら1カウントできる
    return counter(x >> 1) + (x & 1);
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        for(int j = 1; j <= A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    int ans = 0;
    for(int bits = 1; bits < (1 << N); bits++) {
        bool ok = true;
        for(int i = 1; i <= N; i++) {
            if(!(bits & (1 << (i-1)))) continue;
            for(int j = 1; j <= A[i]; j++) {
                // まず証言者が正しいかどうか、加えて証言が正しいかどうか
                // 一致するかどうかを＆と＾で切り替えて１回で見れるのは素晴らしい
                if(((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, counter(bits));
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}
*/