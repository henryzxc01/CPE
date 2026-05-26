//https://zerojudge.tw/ShowProblem?problemid=a741
#include <bits/stdc++.h>
using namespace std;

void f(long long n) {
    if (n >= 10000000) {
        f(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000) {
        f(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000) {
        f(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100) {
        f(n / 100);
        cout << " shata";
        n %= 100;
    }
    if (n) cout << " " << n;
}

int main() {
    long long n;
    int tc = 1;

    while (cin >> n) {
        cout << setw(4) << tc++ << ".";
        if (n == 0) cout << " 0";
        else f(n);
        cout << '\n';
    }
}