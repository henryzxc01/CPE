//https://zerojudge.tw/ShowProblem?problemid=e507
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 競賽加速 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    // 使用 getline 以正確處理空行或含空白的情況
    while (getline(cin, s1) && getline(cin, s2)) {
        
        // 記錄 'a'~'z' 的出現次數 (ASCII 128 足夠涵蓋)
        int cnt1[128] = {0}; 
        int cnt2[128] = {0};

        // 統計 s1
        for (char c : s1) cnt1[c]++;
        
        // 統計 s2
        for (char c : s2) cnt2[c]++;

        // 按照字母順序 (a-z) 輸出
        for (char c = 'a'; c <= 'z'; c++) {
            // 取兩者中較小的次數
            int count = (cnt1[c] < cnt2[c]) ? cnt1[c] : cnt2[c];
            
            // 印出該字母 count 次
            while (count--) {
                cout << c;
            }
        }
        cout << endl; // 每筆測資結束需換行
    }

    return 0;
}
