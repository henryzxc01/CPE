//https://zerojudge.tw/ShowProblem?problemid=d189
#include <iostream>
using namespace std;

int main() {
    int n;
    // 讀入 n 直到 EOF
    while (cin >> n) {
        // 公式：原本喝 n 瓶，加上每 2 個空瓶能多換 1 瓶 (n/2)
        cout << n + n / 2 << endl;
    }
    return 0;
}
