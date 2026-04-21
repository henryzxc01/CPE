//https://zerojudge.tw/ShowProblem?problemid=e543
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 1. 建立鏡像表 (使用 ASCII 直接映射，為了簡潔使用字串查找)
// 只有這些字符有合法的鏡像，空格代表該位置字符無鏡像或鏡像是自己
const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const string rev   = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

// 查找鏡像字符的函數
char getMirror(char c) {
    // 1. 找位置
    int pos = chars.find(c);
    
    // 2. 如果找到了 (不是 npos)，就回傳 rev 對應位置的字
    if (pos != string::npos) {
        return rev[pos];
    }
    
    // 3. 找不到回傳空
    return ' ';
}

int main() {
    string s;
    // 預設輸出訊息，注意前置空格和標點
    const string msg[] = {
        " -- is not a palindrome.",
        " -- is a regular palindrome.",
        " -- is a mirrored string.",
        " -- is a mirrored palindrome."
    };

    while (cin >> s) {
        bool isP = true; // 假設是迴文
        bool isM = true; // 假設是鏡像
        int len = s.length();

        for (int i = 0; i <= len / 2; i++) {
            // 檢查迴文
            if (s[i] != s[len - 1 - i]) isP = false;
            
            // 檢查鏡像
            // 注意：若 getMirror 返回空格，代表該字元無鏡像，直接視為失敗
            if (getMirror(s[i]) != s[len - 1 - i]) isM = false;
        }

        // 計算索引：
        // isP=F, isM=F -> 0
        // isP=T, isM=F -> 1
        // isP=F, isM=T -> 2
        // isP=T, isM=T -> 3
        cout << s << msg[2 * isM + isP] << endl << endl;
    }
    return 0;
}
