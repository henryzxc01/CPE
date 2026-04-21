//https://zerojudge.tw/ShowProblem?problemid=d387
#include <iostream>
using namespace std;

// 使用 bool 節省空間，全域陣列自動初始化為 false (代表是質數)
bool notPrime[1000005]; 

int main() {
    // 1. IO 加速 (必備)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 2. 埃氏篩法建表 (範圍優化：外層只跑到 sqrt，內層從 i*i 開始)
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i * i < 1000005; i++) {
        if (!notPrime[i]) {
            for (int j = i * i; j < 1000005; j += i) {
                notPrime[j] = true;
            }
        }
    }

    int N;
    while (cin >> N) {
        // 先判斷原本是否為質數
        if (notPrime[N]) {
            cout << N << " is not prime.\n";
            continue; // 直接進入下一輪輸入
        }

        // 3. 原地反轉數字
        int temp = N, revN = 0;
        while (temp) {
            revN = revN * 10 + temp % 10;
            temp /= 10;
        }

        // 4. 判斷 Emirp (必須不同且反轉後是質數)
        if (N != revN && !notPrime[revN]) {
            cout << N << " is emirp.\n";
        } else {
            cout << N << " is prime.\n";
        }
    }
    return 0;
}
