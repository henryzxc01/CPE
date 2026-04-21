//https://zerojudge.tw/ShowProblem?problemid=i859
#include <iostream>
using namespace std;

int main() {
    // 優化輸入輸出速度，讓程式跑得更快 (競賽常用)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        // 使用 long long 是因為座標相加後平方會超過 int 範圍
        long long x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        // --- 計算起點 (x1, y1) 的絕對位置 ---
        // 1. 先算出這是第幾層 (層數 = x + y)
        long long sum1 = x1 + y1;
        // 2. 套公式：(層數 * (層數+1)) / 2 算出前面有幾個點，最後加上 x1 (這一層走的步數)
        long long pos1 = sum1 * (sum1 + 1) / 2 + x1;

        // --- 計算終點 (x2, y2) 的絕對位置 ---
        long long sum2 = x2 + y2;
        long long pos2 = sum2 * (sum2 + 1) / 2 + x2;

        // --- 輸出結果 ---
        // 終點位置 - 起點位置 = 移動步數
        cout << "Case " << i << ": " << pos2 - pos1 << "\n";
    }

    return 0;
}
