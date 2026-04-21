//https://vjudge.net/problem/UVA-10221
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // 優化輸入輸出速度 (競賽必備)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double s, a;
    string unit;
    const double PI = acos(-1.0);

    // 持續讀取直到 EOF
    while (cin >> s >> a >> unit) {
        // 地球半徑為 6440 km，加上衛星距離
        double r = s + 6440.0;
        
        // 單位轉換：如果是 "min" (角分)，轉換為度數
        if (unit == "min") a /= 60.0;
        
        // 角度標準化：確保不超過 360 度，且取最短夾角 (<= 180)
        while (a >= 360.0) a -= 360.0;
        if (a > 180.0) a = 360.0 - a;

        // 轉為弧度
        double rad = a * PI / 180.0;
        
        // 弧長公式：r * θ
        double arc = r * rad;
        // 弦長公式：2 * r * sin(θ / 2)
        double chord = 2.0 * r * sin(rad / 2.0);

        // 輸出至小數點後 6 位
        cout << fixed << setprecision(6) << arc << " " << chord << "\n";
    }

    return 0;
}
