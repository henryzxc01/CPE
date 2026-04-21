//https://zerojudge.tw/ShowProblem?problemid=d096
#include <iostream>

using namespace std;

int main() {
    // 解除 C++ 與 C 語言的 I/O 同步，提升讀寫速度（競賽基本操作）
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N 的範圍可達 10^9，計算過程會產生 k^2 (約 2.5 * 10^17)
    // 超過 32-bit int 上限，必須使用 long long 防止溢位
    long long n;
    
    // 持續讀取測資直到檔案結束 (EOF)
    while (cin >> n) {
        // k 代表 N 是等差數列 (1, 3, 5...) 中的第幾個奇數
        // 根據數學規律，從第 1 行到第 N 行，總共恰好有 k^2 個奇數
        long long k = (n + 1) / 2;
        
        // 全體的第 k^2 個奇數值為：2 * (k^2) - 1
        // 該行最後三個奇數分別為：2k^2-1, 2k^2-3, 2k^2-5
        // 三者相加簡化後的常數級 O(1) 公式為：6k^2 - 9
        cout << 6 * k * k - 9 << "\n"; // 競賽中以 \n 換行取代 endl，避免清空緩衝區拖慢速度
    }
    
    return 0;
}
