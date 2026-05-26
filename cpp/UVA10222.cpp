//https://zerojudge.tw/ShowProblem?problemid=e578
#include <bits/stdc++.h>
using namespace std;

int main() {
    string kb = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string s;

    while (getline(cin, s)) {
        for (char c : s) {
            if (c == ' ') cout << c;
            else {
                int p = kb.find(c);
                cout << kb[p - 2];
            }
        }
        cout << '\n';
    }
    return 0;
}