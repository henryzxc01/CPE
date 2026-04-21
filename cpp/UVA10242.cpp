//https://zerojudge.tw/ShowProblem?problemid=e512
#include <iostream>
#include <cstdio> // 使用 printf
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;

    // 持續讀入 4 個座標點 (8 個數字)
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double ansX, ansY;

        // 判斷哪個點是重複的 (連接點)，套用公式：端點1 + 端點2 - 連接點
        if (x1 == x3 && y1 == y3) {
            ansX = x2 + x4 - x1;
            ansY = y2 + y4 - y1;
        } else if (x1 == x4 && y1 == y4) {
            ansX = x2 + x3 - x1;
            ansY = y2 + y3 - y1;
        } else if (x2 == x3 && y2 == y3) {
            ansX = x1 + x4 - x2;
            ansY = y1 + y4 - y2;
        } else { // x2 == x4 && y2 == y4
            ansX = x1 + x3 - x2;
            ansY = y1 + y3 - y2;
        }

        // 題目要求輸出到小數點後 3 位
        printf("%.3f %.3f\n", ansX, ansY);
    }

    return 0;
}
