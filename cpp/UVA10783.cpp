//https://zerojudge.tw/ShowProblem?problemid=c022
#include <iostream>

using namespace std;

int main() {
    // 優化 I/O 速度 (競賽習慣)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, a, b;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> a >> b;
        int sum = 0;
        
        // 核心邏輯：遍歷區間，判斷奇數
        for (int j = a; j <= b; j++) {
            if (j % 2 != 0) { 
                sum += j;
            }
        }

        cout << "Case " << i << ": " << sum << "\n";
    }

    return 0;
}
