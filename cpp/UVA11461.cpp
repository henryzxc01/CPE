//https://zerojudge.tw/ShowProblem?problemid=d186
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 加速 I/O (競賽習慣)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (cin >> a >> b && (a != 0 || b != 0)) {
        // 利用整數截斷特性，直接計算區間內的數量
        // 公式：sqrt(b) - sqrt(a - 1)
        cout << (int)sqrt(b) - (int)sqrt(a - 1) << "\n";
    }

    return 0;
}
