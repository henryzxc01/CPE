//https://vjudge.net/problem/UVA-10209
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double a;
    double pi = acos(-1.0);
    double sq3 = sqrt(3.0);
    
    while (cin >> a) {
        double a2 = a * a;
        
        // 1. 計算單一個「格子」
        double grid = a2 - 2.0 * (pi * a2 / 12.0) - (sq3 / 4.0 * a2);
        
        // 2. 計算單一個「點點」
        double dotted = (a2 - pi * a2 / 4.0) - 2.0 * grid;
        
        // 3. 計算中心「斜線」
        double center = a2 - 4.0 * grid - 4.0 * dotted;
        
        // 題目要求輸出順序：斜線總面積、點點總面積(4個)、格子總面積(4個)
        printf("%.3f %.3f %.3f\n", center, 4.0 * dotted, 4.0 * grid);
    }
    return 0;
}
