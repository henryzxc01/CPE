//https://vjudge.net/problem/UVA-11005
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 優化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        for (int t = 1; t <= T; t++) {
            // 讀取 36 個字元的成本
            // 雖然題目說分4行，但 cin 會自動忽略換行，直接讀入即可
            int cost[36];
            for (int i = 0; i < 36; i++) {
                cin >> cost[i];
            }

            int Q;
            cin >> Q;
            
            // 案例之間需要空行，如果是第二個案例以後，先印空行
            if (t > 1) cout << endl;
            cout << "Case " << t << ":" << endl;

            while (Q--) {
                long long N;
                cin >> N;

                int min_cost = INT_MAX;
                int result_costs[37]; // 暫存每個進位制的成本 (index 2 to 36)

                // 遍歷所有進位制 2 到 36
                for (int b = 2; b <= 36; b++) {
                    long long temp = N;
                    int current_cost = 0;

                    // 計算在 base b 下的成本
                    if (temp == 0) {
                        current_cost = cost[0];
                    } else {
                        while (temp > 0) {
                            current_cost += cost[temp % b];
                            temp /= b;
                        }
                    }
                    
                    result_costs[b] = current_cost;
                    if (current_cost < min_cost) {
                        min_cost = current_cost;
                    }
                }

                // 輸出結果
                cout << "Cheapest base(s) for number " << N << ":";
                for (int b = 2; b <= 36; b++) {
                    if (result_costs[b] == min_cost) {
                        cout << " " << b;
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
