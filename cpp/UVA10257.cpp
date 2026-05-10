#include <iostream>

using namespace std;

int main() {
    // 優化 I/O 速度 (競賽必備)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, p, y, j;
    // 處理多筆測資
    while (cin >> s >> p >> y >> j) {
        int total = 12 + j;
        int Y = (total - p - y) / 3;
        int P = Y + p;
        int S = Y + y;
        
        int rem = total - Y - P - S; // 計算分配後剩下的餘數
        
        if (rem == 1) {
            if (y == s + p) {
                S++;
            } else {
                P++;
            }
        } else if (rem == 2) {
            S++;
            P++;
        }
        
        // 依序輸出 Spot, Puff, Yertle 的年齡
        cout << S << " " << P << " " << Y << "\n";
    }
    
    return 0;
}
