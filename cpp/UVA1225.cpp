//https://zerojudge.tw/ShowProblem?problemid=e528
#include <iostream>
using namespace std;

int main() {
    // 競賽常用的 I/O 加速
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int t, n;
    if (cin >> t) {
        while (t--) {
            cin >> n;
            int c[10] = {0}; // 紀錄 0~9 出現次數的陣列，初始化為 0
            
            // 走訪 1 到 n 的每個數字
            for (int i = 1; i <= n; ++i) {
                // 不斷取餘數與除以 10 來拆解位數
                for (int v = i; v > 0; v /= 10) {
                    c[v % 10]++;
                }
            }
            
            // 依題目要求格式輸出，數字間空白隔開，最後一個數字後直接換行
            for (int i = 0; i < 9; ++i) {
                cout << c[i] << " ";
            }
            cout << c[9] << "\n";
        }
    }
    return 0;
}
