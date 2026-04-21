//https://zerojudge.tw/ShowProblem?problemid=d095
#include <iostream>
#include <cstdio>  // printf 需要這個
#include <cmath>

using namespace std;

int main() {
    double h, m;
    char c;

    // 用 cin 讀取比較方便，可以自動忽略空白並用變數 c 吃掉冒號
    while (cin >> h >> c >> m && (h != 0 || m != 0)) {
        double angle = abs(30 * h - 5.5 * m);
        if (angle > 180) angle = 360 - angle;
        
        // 用 printf 輸出小數點比較簡潔
        printf("%.3f\n", angle);
    }
    return 0;
}
