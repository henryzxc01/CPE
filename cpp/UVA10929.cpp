//https://zerojudge.tw/ShowProblem?problemid=d235
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 競賽加速 IO
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s && s != "0") {
        int rem = 0;
        
        // 逐位處理取模 (Big Integer Modulo)
        for (char c : s) {
            rem = (rem * 10 + (c - '0')) % 11;
        }

        // 輸出結果 (三元運算子簡化判斷)
        cout << s << " is " << (rem ? "not " : "") << "a multiple of 11.\n";
    }
    
    return 0;
}
