//https://zerojudge.tw/ShowProblem?problemid=e555
#include <iostream>

using namespace std;

int main() {
    // 競賽常用的 I/O 加速
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long S, D;
    // 不斷讀取直到 EOF
    while (cin >> S >> D) {
        // 當剩餘天數 D 還大於當前團體人數 S 時
        while (D > S) {
            D -= S++; // 扣除當前團體停留的天數，並將人數直接 +1
        }
        cout << S << "\n";
    }
    return 0;
}


