//https://zerojudge.tw/ShowProblem?problemid=e575
#include <iostream>
using namespace std;

int main() {
    // 優化 IO速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, Q;
        cin >> M >> N >> Q;
        
        // 題目要求先輸出該測資的 M N Q
        cout << M << " " << N << " " << Q << endl;

        char grid[105][105];
        for (int i = 0; i < M; i++) {
            // 直接讀入每一行字串
            cin >> grid[i];
        }

        while (Q--) {
            int r, c;
            cin >> r >> c;
            
            int radius = 1; // 當前嘗試的半徑
            char centerChar = grid[r][c];
            
            while (true) {
                // 1. 檢查邊界 (上下左右是否超出範圍)
                int r_min = r - radius, r_max = r + radius;
                int c_min = c - radius, c_max = c + radius;
                
                if (r_min < 0 || r_max >= M || c_min < 0 || c_max >= N) break;

                // 2. 檢查這一圈的字符是否都與中心相同
                bool isSquare = true;
                
                // 檢查上下兩列
                for (int j = c_min; j <= c_max; j++) {
                    if (grid[r_min][j] != centerChar || grid[r_max][j] != centerChar) {
                        isSquare = false; break;
                    }
                }
                if (!isSquare) break;

                // 檢查左右兩行
                for (int i = r_min; i <= r_max; i++) {
                    if (grid[i][c_min] != centerChar || grid[i][c_max] != centerChar) {
                        isSquare = false; break;
                    }
                }
                if (!isSquare) break;

                // 若通過檢查，擴大半徑
                radius++;
            }

            // 輸出邊長: radius 失敗時停下，故有效半徑為 radius-1
            // 邊長公式 = 2 * (radius-1) + 1
            cout << 2 * (radius - 1) + 1 << endl;
        }
    }
    return 0;
}
