//https://zerojudge.tw/ShowProblem?problemid=c007
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    bool open = true;

    while (cin.get(c)) {
        if (c == '"') {
            cout << (open ? "``" : "''");
            open = !open;
        } else {
            cout << c;
        }
    }

    return 0;
}
