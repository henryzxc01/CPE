//https://zerojudge.tw/ShowProblem?problemid=a134
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> fib = {1, 2};

    while (fib.back() <= 100000000) {
        int n = fib.size();
        fib.push_back(fib[n - 1] + fib[n - 2]);
    }

    int T;
    cin >> T;

    while (T--) {
        int x;
        cin >> x;

        cout << x << " = ";

        bool started = false;

        for (int i = (int)fib.size() - 1; i >= 0; i--) {
            if (fib[i] <= x) {
                cout << '1';
                x -= fib[i];
                started = true;
            } else if (started) {
                cout << '0';
            }
        }

        cout << " (fib)\n";
    }

    return 0;
}