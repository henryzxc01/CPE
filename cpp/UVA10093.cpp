//https://vjudge.net/problem/UVA-10093
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        int sum = 0, mx = 1;

        for (char c : s) {
            int v = -1;

            if ('0' <= c && c <= '9') v = c - '0';
            else if ('A' <= c && c <= 'Z') v = c - 'A' + 10;
            else if ('a' <= c && c <= 'z') v = c - 'a' + 36;

            if (v != -1) {
                sum += v;
                mx = max(mx, v);
            }
        }

        int ans = 0;
        for (int base = mx + 1; base <= 62; base++) {
            if (sum % (base - 1) == 0) {
                ans = base;
                break;
            }
        }

        if (ans) cout << ans << '\n';
        else cout << "such number is impossible!\n";
    }

    return 0;
}
