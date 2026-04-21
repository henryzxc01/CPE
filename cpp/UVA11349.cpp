#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 優化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        char c1, c2;
        long long n;
        // 讀取 "N" 和 "=" 兩個字元，再讀取數字
        cin >> c1 >> c2 >> n;

        long long size = n * n;
        vector<long long> arr(size);
        bool isSymmetric = true;

        // 讀取數據並同時檢查是否為負數
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
            if (arr[i] < 0) isSymmetric = false;
        }

        // 若無負數，檢查是否為迴文 (即中心對稱)
        if (isSymmetric) {
            for (int i = 0; i < size / 2; i++) {
                if (arr[i] != arr[size - 1 - i]) {
                    isSymmetric = false;
                    break;
                }
            }
        }

        cout << "Test #" << t << ": " << (isSymmetric ? "Symmetric." : "Non-symmetric.") << endl;
    }

    return 0;
}
