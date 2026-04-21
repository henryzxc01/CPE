//https://zerojudge.tw/ShowProblem?problemid=d666
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    bool first = true;
    
    // cin >> 會自動忽略空白與換行，完美避開空行的麻煩
    while (cin >> s1 >> s2) {
        if (!first) cout << "\n";
        first = false;
        
        // 字串長度最大 100，進位後不會超過 120
        vector<int> c(120, 0);
        
        // 讀入數字並相加，低位放在陣列低處 (index 0 是最低位)
        for (int i = 0; i < s1.size(); ++i) c[s1.size() - 1 - i] += s1[i] - '0';
        for (int i = 0; i < s2.size(); ++i) c[s2.size() - 1 - i] += s2[i] - '0';
        
        bool changed = true;
        // 不斷套用規則直到沒有任何進位或展開發生
        while (changed) {
            changed = false;
            for (int i = 0; i < 115; ++i) {
                // 規則 1: 處理連續的 1
                if (c[i] && c[i + 1]) {
                    c[i]--; c[i + 1]--; c[i + 2]++;
                    changed = true;
                }
                // 規則 2: 處理同一位數 >= 2
                if (c[i] > 1) {
                    c[i] -= 2;
                    if (i == 0) { c[1]++; }
                    else if (i == 1) { c[2]++; c[0]++; }
                    else { c[i + 1]++; c[i - 2]++; }
                    changed = true;
                }
            }
        }
        
        // 尋找最高位的 1
        int len = 115;
        while (len >= 0 && c[len] == 0) len--;
        
        // 輸出結果
        if (len < 0) {
            cout << 0;
        } else {
            for (int i = len; i >= 0; --i) cout << c[i];
        }
        cout << "\n";
    }
    return 0;
}
