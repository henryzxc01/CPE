//https://zerojudge.tw/ShowProblem?problemid=e516
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 優化 I/O 速度，競賽常用
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    while (cin >> k) {
        if (k == 0) break;
        // 初始狀態：頂=1, 北=2, 西=3
        int t = 1, n = 2, w = 3; 
        string op;
        
        while (k--) {
            cin >> op;
            if (op[0] == 'n') {         // 向北滾 (north)
                int tmp = n; n = t; t = 7 - tmp;
            } else if (op[0] == 's') {  // 向南滾 (south)
                int tmp = t; t = n; n = 7 - tmp;
            } else if (op[0] == 'e') {  // 向東滾 (east)
                int tmp = t; t = w; w = 7 - tmp;
            } else {                    // 向西滾 (west)
                int tmp = w; w = t; t = 7 - tmp;
            }
        }
        cout << t << "\n";
    }
    return 0;
}
