#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
/* すでにチェック済みの数字(char)が10個あったらbreak */
/* すでにチェック済みの数字(char)があったらcontinue */
/* これでACだったけど、もう少し綺麗に書けないもんだろうか。。。。 */

int main() {
  int N; string S; cin >> N >> S;
  set<string> key;
  set<char> checkdata1;
  for (int i = N-1; i >= 2; --i) {
    if (checkdata1.size() == 10) break;
    if (checkdata1.count(S.at(i))) continue;
    set<char> checkdata2;
    for (int j = i-1; j >= 1; --j) {
      if (checkdata2.size() == 10) break;
      if (checkdata2.count(S.at(j))) continue;
      set<char> checkdata3;
      for (int k = j-1; k >= 0; --k) {
        if (checkdata3.size() == 10) break;
        if (checkdata3.count(S.at(k))) continue;
        string pw = {S.at(i), S.at(j), S.at(k)};
        key.insert(pw);
        checkdata3.insert(S.at(k));
      }
      checkdata2.insert(S.at(j));
    }
    checkdata1.insert(S.at(i));
  }
  cout << key.size() << endl;
}

/*
// わかっちゃいたけどこのままだとTLE

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
int main() {
  int N; string S; cin >> N >> S;
  set<string> key;
  for (int i = N-1; i >= 2; --i) {
    for (int j = i-1; j >= 1; --j) {
      for (int k = j-1; k >= 0; --k) {
        string pw = {S.at(i), S.at(j), S.at(k)};
        key.insert(pw);
      }
    }
  }
  cout << key.size() << endl;
}
*/

/*
// 公式解説より
// 3桁の数字->10*10*10＝1000パターン存在するので、pw側がラッキーナンバーから生成できるかを探索する
// なるほどー
// いかに少ないところを検索すればいいかを考えるのが肝

string S; int N, cnt;
int main() {
	cin >> N >> S;
	for (int i = 0; i < 1000; i++) {
    // 1000までの任意の数の各桁を格納 -> {100, 10, 1}
		int c[3] = {i / 100, (i / 10) % 10, i % 10};
    // cの中での桁を指定
		int f = 0;
		for (int j = 0; j < N; j++) {
      // S.at(j)があるかを検索、あれば次のインデックスからはcの一つ先のインデックスのものを探せばOK
			if (S[j] == ('0' + c[f])) f++;
      // 3桁なので、インデックスは2まで。よってfが3になったら終了
			if (f == 3) break;
		}
    // for終了時点でf=3ならkwになりうるので加算
		if (f == 3) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
*/