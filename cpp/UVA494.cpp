//https://zerojudge.tw/ShowProblem?problemid=a011
#include <iostream>
#include <string>
#include <cctype> // 用於 isalpha

using namespace std;

int main() {
    // 競賽常用 I/O 加速
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string line;
    // 使用 getline 一次讀取整行，直到 EOF
    while (getline(cin, line)) {
        int count = 0;
        bool in_word = false;

        for (char c : line) {
            // isalpha() 是標準庫函數，檢查是否為字母 (a-z, A-Z)
            if (isalpha(c)) {
                if (!in_word) {
                    count++;       // 發現新單字
                    in_word = true; // 標記狀態：正在單字中
                }
            } else {
                in_word = false;   // 遇到非字母，重置狀態
            }
        }
        cout << count << endl;
    }
    return 0;
}
