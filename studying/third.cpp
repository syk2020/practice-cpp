#include <bits/stdc++.h>
using namespace std;
int main() {
  // 11. vector
  // 動的配列を生成
  vector<int> v;
  v.push_back(121);
  v.push_back(10);
  v.push_back(1933); // v -> {121, 10, 1933}
  int v1 = v[1]; // v1 -> 10
  v.pop_back(); // v -> {121, 10}
  int v2 = v.size();
  v.push_back(245);
  v.push_back(1456); // v -> {121, 10, 245, 1456}
  // sortする場合
  // 数字指定する場合、第二引数の指定の一つ前になる点に注意
  // v.begin()+3でv[2]の245までが対象になっている
  sort(v.begin(), v.end()); // v -> {10, 121, 245, 1456}
  reverse(v.begin()+1, v.begin()+3); // v -> {10, 245, 121, 1456}

  // 12. stack
  // LIFOを設定できる
  stack<int> s;
  s.push(179);
  s.push(173);
  s.push(156); // s -> 上から {156, 173, 179}
  int s1 = s.top(); // s1 -> 156
  s.pop(); // s -> {173, 179}
  s.push(117);
  s.push(202); // s -> {202, 117, 173, 179}
  s.pop(); // s -> {117, 173, 179}
  int s2 = s.size(); // s2 -> 3
  int s3 = !s.empty() ? 100 : 0; // s3 -> 100 

  // 13. queue
  // FIFOを設定できる
  // 基本的なコマンドはstackとほぼ一緒
  queue<int> q;
  q.push(179);
  q.push(173);
  q.push(156); // q -> 前から{179, 173, 156}
  int q1 = q.front(); // q1 -> 179
  q.pop(); // q -> {173, 156}
  q.push(117);
  q.push(202); // q -> {173, 156, 117, 202}
  q.pop(); // q -> {156, 117, 202}

  // 14. priority_queue
  // 優先度付キュー
  // キューされたデータを自動でソートし、popすると一番大きい値が出ます
  priority_queue<int> pq1;
  pq1.push(5);
  pq1.push(9);
  pq1.push(2);
  int pqnum1 = pq1.top(); // pqnum1 -> 9
  // 一番小さい値を出すときは下記
  priority_queue<int, vector<int>, greater<int>> pq2;
  pq2.push(5);
  pq2.push(9);
  pq2.push(2);
  int pqnum2 = pq2.top(); // pqnum2 -> 2

  // 15. map
  // 値同士の対応表を作成できるデータ構造
  // プリミティブ値だけかと思ったらvectorもできるらしい
  map<int, int> maii;
  maii[0] = 0;
  maii[100] = 5000;
  map<int, string> mais;
  mais[1] = "string";
  mais[7] = "7";
  map<string, double> masd;
  masd["PI"] = 3.14;
  map<int, vector<int>> maiv;
  maiv[0] = {1,2};
  // 初期化
  maiv.clear();

  // 16. lower_bound
  // 知らない関数。二分探索ができるらしい
  // 小さい順にソートされている配列に対し、指定された配列の範囲内で、
  // 指定された値以上になる最初のインデックスを返します
  vector<int> lb;
  lb.push_back(6);
  lb.push_back(2);
  lb.push_back(9);
  lb.push_back(4);
  lb.push_back(3);
  sort(lb.begin(), lb.end()); // lb -> {2, 3, 4, 6, 9}
  auto p = lower_bound(lb.begin(), lb.begin()+5, 7);
  cout << "*p: " << *p << " *prev(p): " << *prev(p) << endl;
  // next()はないので下記の *next(p) は 0 になる
  cout << "*p: " << *p << " *next(p): " << *next(p) << endl;

  // 17. set
  // 重複不可の配列、順序も考慮されない
  set<int> se;
  se.insert(6);
  se.insert(2);
  se.insert(9);
  se.insert(9); // 挿入されない
  se.insert(3);
  se.insert(4);
  se.insert(4); // 挿入されない
  int se1 = se.size(); // se1 -> 5
  // lower_boundsが簡単に使える
  cout << *(se.lower_bound(5)) << endl;
  cout << *(se.upper_bound(2)) << endl;
  // mergeなんてものもある
  set<int> mergeset;
  mergeset.insert(10);
  mergeset.insert(9);
  se.merge(mergeset);
  int se2 = se.size(); // se2 -> 6;
  // 直接構成したい場合はemplaceを使用
  // 消したいときはeraseを使用する
  set<int> setemp;
  setemp.emplace(2,5,6,5);
  setemp.erase(6);
  int se3 = setemp.size(); // se3 -> 2

  // 18. pair
  // 2つの値を紐付ける型
  // これの集合がmap
  // でも実質配列でも組めるので、アクセス方法の違いが問題かな
  pair<int, string> pa[10];
  pa[0].first = 1000;
  pa[0].second = "thousant";
  pa[1].first = 100;
  pa[1].second = "hundred";
  pa[2].first = 100;
  pa[2].second = "hyaku";
  // 比較は、first->secondの順
  cout << (pa[0]<pa[1] ? "Yes" : "No") << endl; // "No",  firstが0のが大きいから
  cout << (pa[1]<pa[2] ? "Yes" : "No") << endl; // "Yes",  firstは同じ、secondが2のが大きいから


  // 19. tuple
  // pairに対し、幾らでも値を紐づけられる仕組み
  tuple<int, int, int> tu = make_tuple(1, 2, 3);
  cout << get<0>(tu) << get<1>(tu) << get<2>(tu) << endl;
  // 読み込みは下記の通り
  tuple<int, int, int> tucin;
  cin >> get<0>(tucin) >> get<1>(tucin) >> get<2>(tucin);
  cout << get<0>(tucin) << get<1>(tucin) << get<2>(tucin)<< endl;
  // vector の値にも tupleは使える
  vector<tuple<int, int, string>> viis;
  viis.push_back(make_tuple(2,2,"string"));

}