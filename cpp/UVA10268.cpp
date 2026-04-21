//https://zerojudge.tw/ShowProblem?problemid=f444
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // 優化 I/O 速度
    ios::sync_with_stdio(0); 
    cin.tie(0);

    long long x;
    while (cin >> x) {
        string line;
        // cin >> x 之後會有換行符號殘留，使用 >> ws 吃掉空白並讀取整行係數
        getline(cin >> ws, line); 
        
        stringstream ss(line);
        vector<int> a;
        int temp;
        // 將整行字串解析為數字陣列
        while (ss >> temp) a.push_back(temp);

        long long ans = 0;
        int n = a.size() - 1; // 多項式的最高次方 (陣列大小 - 1)

        // 使用霍納法則計算導數值
        // 只需跑到 n-1，因為最後一項常數項微分後為 0
        for (int i = 0; i < n; i++) {
            ans = ans * x + (long long)a[i] * (n - i);
        }

        cout << ans << "\n";
    }
    return 0;
}
