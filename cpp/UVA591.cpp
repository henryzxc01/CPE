//https://zerojudge.tw/ShowProblem?problemid=c067
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 優化 IO 速度
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k = 1;
    // 當讀入 n 且 n 不為 0 時執行
    while (cin >> n && n) {
        vector<int> h(n);
        int sum = 0;
        
        // 讀入高度並計算總和
        for (int &x : h) {
            cin >> x;
            sum += x;
        }

        int avg = sum / n;
        int moves = 0;

        // 只計算高於平均的部分
        for (int x : h) {
            if (x > avg) {
                moves += (x - avg);
            }
        }

        // 輸出結果 (注意 UVA 對格式要求嚴格)
        cout << "Set #" << k++ << "\n"
             << "The minimum number of moves is " << moves << ".\n\n";
    }
    return 0;
}
