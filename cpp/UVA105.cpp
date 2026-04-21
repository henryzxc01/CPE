//https://zerojudge.tw/ShowProblem?problemid=d424//
#include <iostream>
#include <algorithm>

using namespace std;

// 題目座標範圍最大為 10000，宣告全域陣列自動初始化為 0
int height_map[10005];

int main() {
    // 優化 IO 速度 (非必須，但在競賽是好習慣)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, H, R, max_r = 0;

    // 1. 讀取輸入並更新高度圖
    while (cin >> L >> H >> R) {
        for (int i = L; i < R; ++i) {
            height_map[i] = max(height_map[i], H);
        }
        max_r = max(max_r, R);
    }

    // 2. 掃描並輸出變化點
    int current_h = 0;
    bool first = true;

    // 掃描到 max_r 即止 (因為 max_r 處高度必歸零或為該處新高度)
    for (int i = 1; i <= max_r; ++i) {
        if (height_map[i] != current_h) {
            if (!first) cout << " "; // 控制空格格式
            cout << i << " " << height_map[i];
            current_h = height_map[i];
            first = false;
        }
    }
    
    cout << endl; // 補上換行
    return 0;
}
