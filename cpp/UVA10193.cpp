//https://zerojudge.tw/ShowProblem?problemid=d306
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            
            int a = stoi(s1, nullptr, 2);
            int b = stoi(s2, nullptr, 2);
            
            // 直接使用 GNU 內建的 __gcd
            cout << "Pair #" << i << ": " 
                 << (__gcd(a, b) > 1 ? "All you need is love!\n" : "Love is not all you need!\n");
        }
    }
    return 0;
}
