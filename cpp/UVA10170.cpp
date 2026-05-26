//https://zerojudge.tw/ShowProblem?problemid=e555
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long S, D;

    while (cin >> S >> D) {
        long long sum = 0;

        while (sum < D) {
            sum += S;
            S++;
        }

        cout << S - 1 << '\n';
    }

    return 0;
}