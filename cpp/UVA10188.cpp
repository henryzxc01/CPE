//https://vjudge.net/problem/UVA-10188
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // 優化輸入輸出速度 (競賽常用)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, run = 0;
    string s;
    
    while (cin >> n && n != 0) {
        getline(cin, s); // 吸收 cin >> n 留下的換行符號
        
        string ans = "", ans_d = "";
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            ans += s + "\n";
            for (char c : s) {
                if (isdigit(c)) ans_d += c;
            }
        }
        
        cin >> m;
        getline(cin, s); // 吸收 cin >> m 留下的換行符號
        
        string out = "", out_d = "";
        for (int i = 0; i < m; ++i) {
            getline(cin, s);
            out += s + "\n";
            for (char c : s) {
                if (isdigit(c)) out_d += c;
            }
        }
        
        cout << "Run #" << ++run << ": ";
        if (ans == out) {
            cout << "Accepted\n";
        } else if (ans_d == out_d) {
            cout << "Presentation Error\n";
        } else {
            cout << "Wrong Answer\n";
        }
    }
    
    return 0;
}
