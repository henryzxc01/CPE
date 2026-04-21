//https://zerojudge.tw/ShowProblem?problemid=a134
#include <iostream>
using namespace std;
int main() {
    // 競賽常用：加速 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 預先建表：題目測資最大到 100,000,000，算到第 39 項即足夠
    int fib[40];
    fib[0] = 1; // 費氏數列在 Zeckendorf 定理中從 1, 2 開始算
    fib[1] = 2;
    for (int i = 2; i < 40; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n, num;
    if (cin >> n) {
        while (n--) {
            cin >> num;
            cout << num << " = ";

            int temp = num;
            bool started = false; // 用來標記是否已經遇到第一個 '1'，避免印出前導零

            // 從最大的費氏數往下找
            for (int i = 39; i >= 0; i--) {
                if (temp >= fib[i]) {
                    cout << "1";
                    temp -= fib[i];
                    started = true;
                } else if (started) {
                    cout << "0";
                }
            }
            cout << " (fib)\n";
        }
    }
    return 0;
}
