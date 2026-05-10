//https://vjudge.net/problem/UVA-10215
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 競賽常用的加速 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double L, W;
    
    while (cin >> L >> W) {
        // 求最大體積的 x (透過微分解)
        double max_x = (L + W - sqrt(L * L - L * W + W * W)) / 6.0;
        
        // 求最小體積的第二個 x (完全剪斷較短邊的狀況)
        double min_x_upper = min(L, W) / 2.0;
        
        // 輸出格式：保留三位小數。
        // 加上 1e-9 是競賽常見技巧，用於避免浮點數四捨五入的微小精確度誤差 (或出現 -0.000)
        printf("%.3f 0.000 %.3f\n", max_x + 1e-9, min_x_upper + 1e-9);
    }
    
    return 0;
}
