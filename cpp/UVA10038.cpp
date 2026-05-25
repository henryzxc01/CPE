//https://zerojudge.tw/ShowProblem?problemid=d097
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    // 循環讀取直到 EOF
    while (cin >> n) {
        vector<bool> diffs(3005, false); // 題目 n <= 3000，用來標記出現過的差值
        int prev, curr;
        
        cin >> prev; // 讀取第一個數
        for (int i = 1; i < n; i++) {
            cin >> curr;
            int d = abs(curr - prev);
            // 只標記範圍在 1 到 n-1 內的差值
            if (d < n) diffs[d] = true;
            prev = curr;
        }

        bool isJolly = true;
        // 檢查是否 1 到 n-1 的差值都出現過
        for (int i = 1; i < n; i++) {
            if (!diffs[i]) {
                isJolly = false;
                break;
            }
        }

        cout << (isJolly ? "Jolly" : "Not jolly") << endl;
    }
    return 0;
}