//https://zerojudge.tw/ShowProblem?problemid=e531
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    // 1. 初始化指法映射表
    // key[音符ASCII][手指編號1-10] = 是否按下
    bool key[128][11] = {0};
    string notes = "cdefgabCDEFGAB";
    // 對應的指法 (0代表第10指)
    string pats[] = {
        "2347890", "234789", "23478", "2347", "234", "23", "2", // c-b
        "3", "1234789", "123478", "12347", "1234", "123", "12"  // C-B
    };

    for (int i = 0; i < 14; i++) {
        for (char c : pats[i]) {
            int finger = (c == '0' ? 10 : c - '0');
            key[notes[i]][finger] = true;
        }
    }

    // 2. 處理輸入
    int t;
    cin >> t;
    string s;
    getline(cin, s); // 消耗掉 t 後面的換行

    while (t--) {
        getline(cin, s);
        int cnt[11] = {0};
        bool last[11] = {0}; // 紀錄上一音符的手指狀態，初始為全放開

        for (char c : s) {
            for (int f = 1; f <= 10; f++) {
                bool current_press = key[c][f];
                // 如果「現在要按」且「之前沒按」，計數器+1
                if (current_press && !last[f]) {
                    cnt[f]++;
                }
                // 更新此手指的狀態供下一個音符比對
                last[f] = current_press;
            }
        }

        // 3. 輸出結果
        for (int i = 1; i <= 10; i++)
            cout << cnt[i] << (i == 10 ? "" : " ");
        cout << endl;
    }

    return 0;
}
