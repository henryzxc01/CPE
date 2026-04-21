//https://zerojudge.tw/ShowProblem?problemid=a132
#include <iostream>
#include <string>
#include <algorithm> // 用於 reverse

using namespace std;

int main() {
    // 優化輸入輸出速度 (競賽必備)
    ios::sync_with_stdio(0);
    cin.tie(0);

    int I;
    while (cin >> I && I != 0) {
        string binary = "";
        int count = 0;
        int temp = I;

        // 位元處理核心邏輯
        while (temp > 0) {
            if (temp & 1) {     // 檢查最低位是否為 1
                binary += '1';
                count++;        // 累計 Parity
            } else {
                binary += '0';
            }
            temp >>= 1;         // 向右位移 (除以 2)
        }

        // 因為是從最低位 (LSB) 開始取，字串需要反轉
        reverse(binary.begin(), binary.end());

        cout << "The parity of " << binary << " is " << count << " (mod 2)." << endl;
    }

    return 0;
}
