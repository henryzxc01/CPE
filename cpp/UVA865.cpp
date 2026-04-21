//https://zerojudge.tw/ShowProblem?problemid=e501
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 優化輸入輸出速度 (競賽必備)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string line;
    
    // 讀取測資筆數，並吃掉後面的換行與第一個空白行
    if (getline(cin, line)) {
        t = stoi(line);
        getline(cin, line); 

        while (t--) {
            string plain, cipher;
            getline(cin, plain);
            getline(cin, cipher);

            // 依題目要求先輸出 cipher 再輸出 plain
            cout << cipher << "\n" << plain << "\n";

            // 建立 ASCII 映射表，預設每個字元映射到自己
            char map[256];
            for (int i = 0; i < 256; ++i) map[i] = i;
            
            // 根據輸入更新映射表
            for (int i = 0; i < plain.length(); ++i) {
                map[plain[i]] = cipher[i];
            }

            // 讀取要替換的文字，直到遇到空白行或 EOF
            while (getline(cin, line) && !line.empty()) {
                for (char c : line) {
                    cout << map[c];
                }
                cout << "\n";
            }
            
            // 測資之間需輸出一個空白行 (最後一筆不用)
            if (t) cout << "\n";
        }
    }
    return 0;
}
