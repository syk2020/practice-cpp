#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)

/* 未完、TLE */
/* キューで実装できることは思いついたけど、優先度付キューを知らず敗北 */

int main() {
    int n;
    cin >> n;
    queue<long long> que;
    REP (i, n) {
        int c;
        cin >> c;
        switch (c) {
            case 1:
                long long x;
                cin >> x;
                que.push(x);
                break;
            case 2:
                cout << que.front() << endl;
                que.pop();
                break;
            case 3:
                vector<long long> v;
                while (!que.empty()) {
                    v.push_back(que.front());
                    que.pop();
                }
                sort(v.begin(), v.end());
                REP (j, v.size()) {
                    que.push(v[j]);
                }
                break;
        }
    }

    /*
    // 後からACになったバージョン
    // 優先度付きキューを知っていればー！

    int main() {
        int n;
        cin >> n;
        queue<int> que1;
        priority_queue<int, vector<int>, greater<int>> que2;
        REP (i, n) {
            int c;
            cin >> c;
            switch (c) {
                case 1:
                    int x;
                    cin >> x;
                    que1.push(x);
                    break;
                case 2:
                    if (que2.empty()) {
                        cout << que1.front() << endl;
                        que1.pop();
                    } else {
                        cout << que2.top() << endl;
                        que2.pop();
                    }
                    break;
                case 3:
                    while (!que1.empty()) {
                        que2.push(que1.front());
                        que1.pop();
                    }
                    break;
            }
        }
    }
    */
}