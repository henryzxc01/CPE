//https://zerojudge.tw/ShowProblem?problemid=c031
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int k = 1, pos = n;
        // 找出 n 落在哪一條對角線 (k)
        // 第一條有1個, 第二條有2個... 依此類推減去
        while (pos > k) {
            pos -= k;
            k++;
        }
        
        cout << "TERM " << n << " IS ";
        // 奇數對角線：左下往右上 (分子遞減，分母遞增) -> 修正：實際觀察題目是分子遞減沒錯，但起點是左下
        // 偶數對角線：右上往左下 (分子遞增，分母遞減)
        // 注意：pos 是該對角線中的第幾個元素
        
        if (k % 2 == 1) 
            cout << k - pos + 1 << "/" << pos << endl;
        else 
            cout << pos << "/" << k - pos + 1 << endl;
    }
    return 0;
}
