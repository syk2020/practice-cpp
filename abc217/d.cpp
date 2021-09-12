#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)

/* 未完 */
/* set型（他、C++で使えるデータ構造）を知らない時点で詰んでいた */

int main() {
    long long l;
    int q;
    cin >> l >> q;
    vector<int> cut;
    REP (i, q) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            if (cut.size() == 0) {
                cut.push_back(x);
                cout << "IT" << endl;
            } else {
                if (x > cut[cut.size()-1]) cut.push_back(x);
                else {
                    cout << "NONE" << endl;
                    auto jt = cut.begin();
                    REP (j, cut.size()) {
                        if (x < cut[j+1]) {

                            jt = jt + j;
                            cout << "j:" << j << endl;
                            cut.insert(jt, x);
                            break;
                        } else continue;
                    }
                }
            }
            //auto chcont = find(cut.begin(), cut.end(), x);
            //cout << *chcont << endl;
            /*if(cut.size() > 0) {
                if(chcont == cut.end()) cut.push_back(x);
                else cut.insert(chcont-1, x);
            } else cut.push_back(x);*/
        }/* else {
            REP (j, 0, n) {
                if(x > cut[j]
            }
            //auto endpl = find(cut.begin(), cut.end(), x);
            //if (endpl == cut.end()) {

            //}
        }*/


    }

        REP (i, cut.size()) {
            cout << cut[i] << endl;
        }

}