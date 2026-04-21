#include <iostream>
using namespace std;

// 定義遞迴函數：計算數根
int f(int n) {
    // 終止條件：如果剩下個位數，直接回傳
    if (n < 10) return n;
    
    // 計算各位數總和
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    // 將總和再次傳入函數 (遞迴)
    return f(sum);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << f(n) << endl;
    }
    return 0;
}
