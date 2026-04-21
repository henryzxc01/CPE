//https://zerojudge.tw/ShowProblem?problemid=d672
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 競賽 IO 加速
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s && s != "0") {
        int n = 0;
        // 第一次計算位數和 (Step 1)
        for (char c : s) {
            n += c - '0';
        }

        // 檢查是否為 9 的倍數
        if (n % 9 != 0) {
            cout << s << " is not a multiple of 9.\n";
        } else {
            int degree = 1;
            // 如果目前的和還大於 9，繼續做位數加總 (Step 2, 3...)
            while (n > 9) {
                int sum = 0;
                while (n > 0) {
                    sum += n % 10;
                    n /= 10;
                }
                n = sum;
                degree++;
            }
            // 修正點：輸出必須是 "9-degree"
            cout << s << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        }
    }
    return 0;
}
