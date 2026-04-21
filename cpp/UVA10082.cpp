//https://zerojudge.tw/ShowProblem?problemid=c054
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 建立鍵盤對應字串 (注意反斜線 \ 需要跳脫寫成 \\)
    string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c;
    
    // 逐字元讀取，包含空白與換行
    while (cin.get(c)) {
        auto p = s.find(c);
        // 若在字串中找到該字元，輸出其左邊的字元；否則直接輸出原字元 (如空白、換行)
        if (p != string::npos) cout << s[p - 1];
        else cout << c;
    }
    
    return 0;
}
