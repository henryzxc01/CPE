//https://vjudge.net/problem/UVA-12019#author=tingshuo
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 優化 IO 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, M, D;
    // 定義每個月的天數 (2011 不是閏年)
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 定義星期字串，注意順序對應模運算
    // 1/1 是星期六 => (1 + k) % 7 = 5 (Saturday 在陣列 index 5) => k = 4
    // 故 Index 0 = Monday, ... Index 5 = Saturday
    string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    cin >> cases;
    while (cases--) {
        cin >> M >> D;
        
        int total_days = 0;
        
        // 累加該月之前的所有天數
        for (int i = 1; i < M; ++i) {
            total_days += days[i];
        }
        
        // 加上當月天數
        total_days += D;
        
        // 計算星期：(總天數 + 位移修正) % 7
        // 位移修正為 4，因為 1/1 (第1天) 必須對應到 index 5 (Saturday) -> (1+4)%7 = 5
        cout << week[(total_days + 4) % 7] << endl;
    }

    return 0;
}
