//https://zerojudge.tw/ShowProblem?problemid=c004
#include <iostream>
using namespace std;

int main() {
    // 優化 IO 速度
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int s, d; // 使用 long long 防止 s+d 溢位
        cin >> s >> d;

        // 判斷無解：差大於和 或 和差奇偶性不同(相加為奇數)
        if (s < d || (s + d) % 2 != 0) {
            cout << "impossible\n";
        } else {
            // 直接輸出公式解，大的在前
            cout << (s + d) / 2 << " " << (s - d) / 2 << "\n";
        }
    }
    return 0;
}
