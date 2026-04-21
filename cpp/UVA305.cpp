//https://zerojudge.tw/ShowProblem?problemid=c108
//因為 k 的範圍很小 (1 到 13)，我們可以在本地端寫一個程式，針對每一個 k，從 m=1 開始嘗試，直到找到一個 m 能讓所有壞人先被處決。
#include <iostream>
#include <vector>

using namespace std;

// 檢查對於特定的 k，數字 m 是否合法
bool is_valid(int k, int m) {
    int current_pos = 0;
    int len = 2 * k; // 當前剩餘人數
    
    // 必須連續處決 k 個壞人
    for (int i = 0; i < k; i++) {
        // Josephus 公式：找出下一個要殺的人的位置
        current_pos = (current_pos + m - 1) % len;
        
        // 如果位置小於 k，代表殺到了好人 (好人索引是 0 ~ k-1)
        if (current_pos < k) return false;
        
        // 殺掉壞人後，圓圈變小，且被殺掉的位置成為下一輪的起點(邏輯上)
        // 因為陣列縮小，後面的元素往前遞補，所以 current_pos 不需要改變即可指到下一個人
        len--; 
    }
    return true;
}

int main() {
    cout << "int ans[] = {0"; // 格式化輸出
    
    // 針對 k = 1 到 13 計算答案
    for (int k = 1; k < 14; k++) {
        int m = k + 1; // m 至少要比 k 大 (否則第一次就會殺到好人)
        
        while (true) {
            if (is_valid(k, m)) {
                cout << ", " << m;
                break; // 找到最小的 m，跳出換下一個 k
            }
            m++;
            
            // 優化：若是 k=13，m 可能很大，可以觀察 m % (2*k) 的特性來加速，
            // 但因為只要跑一次，簡單暴力法跑幾秒鐘也能出來。
        }
    }
    cout << "};" << endl;
    
    return 0;
}
//直接計算k=13的情況需要耗費大量時間，容易導致 TLE (Time Limit Exceeded)，預先算出答案存入陣列是最佳策略。
#include <iostream>

using namespace std;

int main() {
    // 加速 I/O
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // 預先計算好的答案 (對應 k=1 到 k=13)
    // 陣列索引 0 留空，索引 1 對應 k=1 的答案 2，以此類推
    int ans[] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
    
    int k;
    while (cin >> k && k != 0) {
        cout << ans[k] << "\n";
    }

    return 0;
}
