//https://vjudge.net/problem/UVA-10018
#include <iostream>

using namespace std;

int main() {
    // 競賽常用的 I/O 加速
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        while (n--) {
            long long num, rev, temp;
            int count = 0;
            cin >> num;

            // 核心邏輯
            while (true) {
                rev = 0;
                temp = num;
                
                // 計算反轉數字
                while (temp > 0) {
                    rev = rev * 10 + temp % 10;
                    temp /= 10;
                }

                // 若與反轉後相等代表已是迴文，跳出迴圈
                if (num == rev) break;

                // 否則相加並增加次數
                num += rev;
                count++;
            }
            
            cout << count << " " << num << "\n";
        }
    }
    return 0;
}
