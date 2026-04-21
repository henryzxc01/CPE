//https://zerojudge.tw/ShowProblem?problemid=e537
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int len = s.length();
        
        // 嘗試所有可能的週期長度 k
        for (int k = 1; k <= len; ++k) {
            // 只有當總長度能被 k 整除時，k 才可能是週期
            if (len % k == 0) {
                int i = k;
                // 檢查是否符合週期性：s[i] 必須等於 s[i % k]
                for (; i < len; ++i) {
                    if (s[i] != s[i % k]) break;
                }
                
                // 如果迴圈跑完 (i == len)，代表找到最小週期
                if (i == len) {
                    cout << k << "\n";
                    break; 
                }
            }
        }
        
        // 題目要求：相鄰兩筆輸出的測試資料間需有一個空行（最後一筆不用）
        if (T) cout << "\n";
    }
    return 0;
}
