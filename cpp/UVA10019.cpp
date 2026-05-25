//https://zerojudge.tw/ShowProblem?problemid=e545
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;

        int b1 = __builtin_popcount(n);

        int b2 = 0;
        while (n) {
            b2 += __builtin_popcount(n % 10);
            n /= 10;
        }

        cout << b1 << ' ' << b2 << '\n';
    }

    return 0;
}