//https://zerojudge.tw/ShowProblem?problemid=d123
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, caseNum = 1;
    // 連續讀取輸入直到 EOF
    while (cin >> n) {
        vector<int> a(n);
        bool isB2 = true;

        // 輸入並檢查基本條件：必須正整數且嚴格遞增
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < 1 || (i > 0 && a[i] <= a[i-1])) {
                isB2 = false;
            }
        }

        // 檢查所有 pair 的和是否重複
        if (isB2) {
            // 題目最大測資約 10000，兩數和最大約 20000，開 20005 足夠
            bool sumSeen[20005] = {false};
            
            for (int i = 0; i < n && isB2; i++) {
                for (int j = i; j < n; j++) {
                    int s = a[i] + a[j];
                    if (sumSeen[s]) {
                        isB2 = false;
                        break;
                    }
                    sumSeen[s] = true;
                }
            }
        }

        // 輸出結果，注意題目要求每個 Case 後有一空行
        cout << "Case #" << caseNum++ << ": It is " 
             << (isB2 ? "" : "not ") 
             << "a B2-Sequence.\n" << endl;
    }
    return 0;
}
