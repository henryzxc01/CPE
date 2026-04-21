//https://zerojudge.tw/ShowProblem?problemid=c014
#include <iostream>
using namespace std;

int main() {
    // 競賽常用：優化標準輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b;
    // 當 a, b 成功讀入且兩者不全為 0 時繼續執行
    while (cin >> a >> b && (a || b)) {
        int carry = 0, count = 0;
        
        // 直到兩個數字都被除到 0 為止
        while (a || b) {
            // 判斷當下位數相加加上前次進位是否大於 9
            carry = (a % 10 + b % 10 + carry) > 9;
            count += carry; // 直接將 boolean 結果 (0 或 1) 加到總數
            a /= 10;
            b /= 10;
        }
        
        // 依據進位次數輸出對應結果
        if (!count) cout << "No carry operation.\n";
        else if (count == 1) cout << "1 carry operation.\n";
        else cout << count << " carry operations.\n";
    }
    
    return 0;
}
