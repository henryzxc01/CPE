//https://zerojudge.tw/ShowProblem?problemid=c045
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 提升 I/O 效能，競賽基本操作
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s[105];
    int n = 0, max_len = 0;

    // 逐行讀取輸入
    while (getline(cin, s[n])) {
        // 記錄最長字串的長度，決定輸出會有幾列
        if (s[n].length() > max_len) {
            max_len = s[n].length();
        }
        n++;
    }

    // i 控制輸出的列（對應原字串的字元索引）
    for (int i = 0; i < max_len; i++) {
        // j 控制輸出的行（由最後輸入的字串往前印）
        for (int j = n - 1; j >= 0; j--) {
            // 如果該字串長度足夠，就印出字元；否則印出空格補齊
            if (i < s[j].length()) {
                cout << s[j][i];
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
