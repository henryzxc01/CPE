//https://zerojudge.tw/ShowProblem?problemid=e605
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 優化輸入輸出速度 (競賽必備)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cases = 1;
    
    // 當讀入 n, m 且兩者不全為 0 時繼續執行
    while (cin >> n >> m && (n || m)) {
        // 處理格式：除了第一筆測資外，前面的輸出都要多換一行
        if (cases > 1) cout << '\n';
        cout << "Field #" << cases++ << ":\n";

        // 讀取地圖
        vector<string> g(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }

        // 掃描每個格子
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    cout << '*'; // 是地雷直接輸出
                } else {
                    int count = 0;
                    // 檢查九宮格 (包含自己也沒關係，因為自己不是 '*')
                    for (int dy = -1; dy <= 1; dy++) {
                        for (int dx = -1; dx <= 1; dx++) {
                            int ny = i + dy;
                            int nx = j + dx;
                            // 確保邊界不超範圍，且該位置為地雷
                            if (ny >= 0 && ny < n && nx >= 0 && nx < m && g[ny][nx] == '*') {
                                count++;
                            }
                        }
                    }
                    cout << count;
                }
            }
            cout << '\n'; // 每一列結束後換行
        }
    }

    return 0;
}
