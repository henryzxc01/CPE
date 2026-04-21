//https://zerojudge.tw/ShowProblem?problemid=d206
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // UVA 系統通常建議使用 EOF 判斷讀取
    while (cin >> n) {
        int a[105][105] = {0};
        
        // 讀取測資並同時建立「直行」的前綴和
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                a[i][j] += a[i - 1][j]; 
            }
        }

        int ans = -2e9; // 預設最大值為一個極小數字，以處理全負數陣列的情況

        // 窮舉所有可能的上下邊界 (i 為上邊界，j 為下邊界)
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int sum = 0;
                
                // 將 2D 問題降維，對每一行使用 1D 的 Kadane's 演算法
                for (int k = 1; k <= n; ++k) {
                    // 區間 [i, j] 在第 k 直行的總和
                    int val = a[j][k] - a[i - 1][k];
                    
                    // 決定要延續前面的連續總和，還是從當前這格重新開始算
                    sum = max(val, sum + val);
                    
                    // 更新歷史最大值
                    ans = max(ans, sum);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
