//https://zerojudge.tw/ShowProblem?problemid=e549
#include <iostream>
#include <algorithm> // 補上 max/min 需要的標頭檔
using namespace std;

const int INF = 1e9; // 宣告夠大的常數，避免負數座標的坑

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x, y, z, L;
    while (cin >> n && n != 0) {
        // 下界設為極小，上界設為極大，包容所有可能的座標
        int x1 = -INF, x2 = INF;
        int y1 = -INF, y2 = INF;
        int z1 = -INF, z2 = INF;
        
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z >> L;
            x1 = max(x1, x); x2 = min(x2, x + L);
            y1 = max(y1, y); y2 = min(y2, y + L);
            z1 = max(z1, z); z2 = min(z2, z + L);
        }
        
        // 你的神來一筆：用 max(0, 交集長度) 濾掉負數
        cout << max(0, x2 - x1) * max(0, y2 - y1) * max(0, z2 - z1) << "\n";
    }
    return 0;
}
