//https://vjudge.net/problem/UVA-10126
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    // 優化輸入輸出速度 (競賽常用)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    bool first = true;
    
    while (cin >> n) {
        if (!first) cout << "\n";
        first = false;

        map<string, int> cnt;
        string s = "";
        char c;
        
        // 逐字元讀取文本
        while (cin.get(c)) {
            if (isalpha(c)) {
                s += tolower(c); // 統一轉小寫
            } else if (!s.empty()) {
                if (s == "endoftext") break; // 遇到結束標記即跳出
                cnt[s]++;
                s = "";
            }
        }

        bool found = false;
        // std::map 預設會依據 Key (字串) 的字典序進行排序
        for (auto it : cnt) {
            if (it.second == n) {
                cout << it.first << "\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "There is no such word.\n";
        }
    }
    return 0;
}
