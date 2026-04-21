//https://zerojudge.tw/ShowProblem?problemid=d750
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;

// 核心比較函數
bool compare(int a, int b) {
    // 1. 比較餘數
    if (a % M != b % M) {
        return a % M < b % M;
    }
    
    // 2. 餘數相同，處理奇偶性
    // 使用 abs() % 2 確保負數也能正確判斷奇偶 (或是直接檢查是否不為0)
    bool a_is_odd = abs(a) % 2;
    bool b_is_odd = abs(b) % 2;
    
    if (a_is_odd != b_is_odd) {
        // 一奇一偶：奇數優先
        return a_is_odd; 
    }
    
    // 同奇或同偶
    if (a_is_odd) {
        // 同奇：大的在先
        return a > b;
    } else {
        // 同偶：小的在先
        return a < b;
    }
}

int main() {
    // 優化 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> M) {
        // 依照題目要求，最後需要輸出 0 0 代表結束，但每組測資開頭也要輸出 N M
        cout << N << " " << M << endl;
        
        if (N == 0 && M == 0) break;

        vector<int> nums(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end(), compare);

        for (int i = 0; i < N; i++) {
            cout << nums[i] << endl;
        }
    }
    return 0;
}
