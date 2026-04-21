//https://vjudge.net/problem/UVA-10093
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 優化輸入輸出速度（競賽常用）
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    while (cin >> s) {
        int sum = 0, mx = 1; // mx 預設為 1，確保最小從 2 進位開始計算
        
        // 計算各位數字的十進位總和，並找出出現過的最大字元值
        for (char c : s) {
            int v = 0;
            if (c >= '0' && c <= '9') v = c - '0';
            else if (c >= 'A' && c <= 'Z') v = c - 'A' + 10;
            else if (c >= 'a' && c <= 'z') v = c - 'a' + 36;
            else continue; // 忽略正負號或其他非英數符號
            
            sum += v;
            if (v > mx) mx = v;
        }
        
        // 尋找符合條件的最小進位制 (N)
        int ans = 0;
        for (int i = mx + 1; i <= 62; ++i) {
            if (sum % (i - 1) == 0) {
                ans = i;
                break;
            }
        }
        
        // 輸出結果
        if (ans) cout << ans << "\n";
        else cout << "such number is impossible!\n";
    }
    
    return 0;
}
