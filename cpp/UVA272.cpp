#include <iostream>
#include <string>

using namespace std;

int main() {
    // 競賽常用的 I/O 加速
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    string s;
    bool open = true; // 狀態可以跨行保留
    
    // 逐行讀取直到 EOF
    while (getline(cin, s)) {
        for (char c : s) {
            if (c == '"') {
                cout << (open ? "``" : "''");
                open = !open;
            } else {
                cout << c;
            }
        }
        cout << '\n'; // getline 會吃掉換行符號，需要手動補上
    }
    
    return 0;
}
