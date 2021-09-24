#include <bits/stdc++.h>
using namespace std;

/* 変な場合分けをしてこんがらがってしまった */
/* 出力結果の直前で確認すればOKだった */
/* 構造体を作った時は、最後 }; とする必要がある */

// 以下に、24時間表記の時計構造体 Clock を定義する

struct Clock {
// Clock構造体のメンバ変数を書く
//   int hour    時間を表す (0~23の値をとる)
//   int minute  分を表す   (0~59の値をとる)
//   int second  秒を表す   (0~59の値をとる)
  int hour;
  int minute;
  int second;

// メンバ関数 set の定義を書く
//   関数名: set
//   引数: int h, int m, int s (それぞれ時、分、秒を表す)
//   返り値: なし
//   関数の説明:
//     時・分・秒を表す3つの引数を受け取り、
//     それぞれ、メンバ変数 hour, minute, second に代入する
  void set (int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
  }

// メンバ関数 to_str の定義を書く
//   関数名: to_str
//   引数: なし
//   返り値: string型
//   関数の仕様:
//     メンバ変数が表す時刻の文字列を返す
//     時刻の文字列は次のフォーマット
//     "HH:MM:SS"
//     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
  string to_str () {
    string str = "";
    /*
    if (hour < 10) str += "0";
    str += (to_string(hour)) + ":");
    で良かったんだった
    */
    if (hour < 10) str += ("0" + to_string(hour));
    else str += to_string(hour);
    str += ":";
    if (minute < 10) str += ("0" + to_string(minute));
    else str += to_string(minute);
    str += ":";
    if (second < 10) str += ("0" + to_string(second));
    else str += to_string(second);
    return str;
  }

// メンバ関数 shift の定義を書く
//   関数名: shift
//   引数: int diff_second
//   返り値: なし
//   関数の仕様:
//     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
//     diff_second の値が負の場合、時刻を戻す
//     diff_second の値が正の場合、時刻を進める
//     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
  void shift (int diff_second) {
    int now_second = hour * 3600 + minute * 60 + second;
    now_second += diff_second;
    if (now_second < 0) now_second += 86400;
    else if (now_second >= 86400) now_second -= 86400;
    /*
    // 変な条件わけ
    // 戒めを込めて残しとく

    // diff_secondが負の場合
    if (diff_second < 0) {
      // now_secondの方が大きい場合
      if (now_second > diff_second) {
        now_second -= diff_second;
      }
      // now_secondの方が小さい場合
      else if (now_second < diff_second) {
        now_second = now_second + 86400 - diff_second;
      }
      else now_second = 0;
    }
    // diff_secondが正の場合
    else if (diff_second > 0) {
      // now_secondに先に足す
      now_second += diff_second;
          // 1日より大きい場合
      if (now_second >= 86400) {
        now_second -= 86400;
      }
      // 1日より小さい場合は変更なし
    }
    */
    // minuteはhourの分の秒数を引いておかないと60秒を超えてしまう 
    hour = now_second / 3600;
    minute = (now_second - hour * 3600) / 60;
    // minute = (now_second % hour) / 60; でも良かった
    second = now_second % 60;
  }
};

// -------------------
// ここから先は変更しない
// -------------------

int main() {
  // 入力を受け取る
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock構造体のオブジェクトを宣言
  Clock clock;

  // set関数を呼び出して時刻を設定する
  clock.set(hour, minute, second);

  // 時刻を出力
  cout << clock.to_str() << endl;

  // 時計を進める(戻す)
  clock.shift(diff_second);

  // 変更後の時刻を出力
  cout << clock.to_str() << endl;
}
