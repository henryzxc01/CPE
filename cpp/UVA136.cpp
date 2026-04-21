//https://zerojudge.tw/ShowProblem?problemid=d129
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // 競賽常用的 I/O 加速
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u[1500] = {1}; 
    int p2 = 0, p3 = 0, p5 = 0;

    for (int i = 1; i < 1500; ++i) {
        // 找出下一個最小的醜數
        u[i] = min({u[p2] * 2, u[p3] * 3, u[p5] * 5});
        
        // 移動對應的指標，注意這裡不使用 else if 以避免重複數字 (如 2*3 == 3*2)
        if (u[i] == u[p2] * 2) p2++;
        if (u[i] == u[p3] * 3) p3++;
        if (u[i] == u[p5] * 5) p5++;
    }

    cout << "The 1500'th ugly number is " << u[1499] << ".\n";
    
    return 0;
}
