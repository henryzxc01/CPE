//https://zerojudge.tw/ShowProblem?problemid=e566
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. I/O 加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        // 2. 邊界檢查優化：
        // n < 2: 序列必須從大於1的數開始
        // m < 2: 除數必須大於1，否則 m=1 會導致無窮迴圈，m=0 會導致除以零錯誤
        if (n < 2 || m < 2) {
            cout << "Boring!\n";
            continue;
        }

        vector<int> ans;
        ans.push_back(n); // 先放入第一個數
        
        bool boring = false;
        while (n > 1) {
            if (n % m == 0) {
                n /= m;
                ans.push_back(n);
            } else {
                boring = true;
                break;
            }
        }

        // 3. 輸出邏輯
        if (boring) {
            cout << "Boring!\n";
        } else {
            // 4. 避免行尾多餘空白的寫法
            for (int i = 0; i < ans.size(); i++) {
                // 如果不是第一個元素，先印空白
                if (i > 0) cout << " "; 
                cout << ans[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
