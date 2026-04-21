//https://zerojudge.tw/ShowProblem?problemid=e578
#include <iostream>
#include <string>

using namespace std;

int main() {
    string k = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string s;

    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                cout << " ";
            } else {
                for (int j = 0; j < k.length(); j++) {
                    if (k[j] == s[i]) {
                        cout << k[j - 2];
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
