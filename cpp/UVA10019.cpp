//https://zerojudge.tw/ShowProblem?problemid=e545
#include <iostream>

using namespace std;

int main() {
    // 優化輸入輸出速度（競賽常用）
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    if (cin >> t) {
        while (t--) {
            cin >> n;

            // b1: 將 n 視為十進位時，二進位表示法中 1 的數量
            int b1 = __builtin_popcount(n);

            // b2: 將 n 視為十六進位時，二進位表示法中 1 的數量
            int b2 = 0;
            int temp = n;
            while (temp > 0) {
                // 取出十進位的每一個數字當作十六進位的位數，並計算該數字轉二進位後 1 的數量
                b2 += __builtin_popcount(temp % 10);
                temp /= 10;
            }

            // 輸出結果
            cout << b1 << " " << b2 << "\n";
        }
    }
    return 0;
}
