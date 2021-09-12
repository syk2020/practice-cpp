#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (n); i++)
int main() {
	int n;
	cin >> n;
	int ar[n];
	REP (i, 0, n) {
		cin >> ar[i];
	}
	int res[n];
	REP (i, 0, n) {
		res[ar[i]-1] = i + 1;
	}
	REP (i, 0, n) {
		cout << res[i];
		if (i != n-1) cout << " ";
		else cout << endl;
	}
  /*
  resのインデックスとして登録する段階で-1するのではなくて、
  arに読み込む段階で-1しておきたい

  for で回すとき、pの中身を参照する形にして突っ込んでいく方法（以下、公式解説より）
  vector<int> p(N), q(N);
  for (auto &x : p) cin >> x, --x;
  ※ この時、最後 x-- では読み込んだ数値のままなので、必ず --x にすること

  REP(i, N) q[p[i]] = i;
  REP(i, N) cout << q[i] + 1 << " \n"[i == N - 1];
  ※ +1 で読み込んだデータを復元
  ※ " \n"[i == N - 1] -> []内の式がTRUEの時のみ2文字目（インデックス1）が読み込まれる
  　競プロ匠の技や……

  */
}