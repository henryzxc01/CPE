//https://zerojudge.tw/ShowProblem?problemid=d182
#include <iostream>
#include <iomanip> // 用於 setw 和 setfill

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int limit = 1;
        // 計算切割點，例如 N=4 時 limit=100 (因為 10^(4/2))
        // 同時 limit 也是窮舉平方根的上限
        for (int i = 0; i < n / 2; i++) limit *= 10;

        for (int i = 0; i < limit; i++) {
            int square = i * i;
            
            // 題目要求： (前半段 + 後半段)^2 == 原數
            // 因為我們是用 i 的平方產生原數，所以只要檢查 (前半段 + 後半段) == i 即可
            if ((square / limit) + (square % limit) == i) {
                // 輸出需補前導 0 補滿 N 位
                cout << setw(n) << setfill('0') << square << endl;
            }
        }
    }
    return 0;
}
