//https://zerojudge.tw/ShowProblem?problemid=e534
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> p[6];
    
    // 讀取直到 EOF
    while (cin >> p[0].first >> p[0].second) {
        if (p[0].first > p[0].second) swap(p[0].first, p[0].second);
        
        for (int i = 1; i < 6; ++i) {
            cin >> p[i].first >> p[i].second;
            if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
        }
        
        // 依照 pair 預設的字典序排序
        sort(p, p + 6);
        
        // 判斷是否滿足構成長方體的條件
        if (p[0] == p[1] && p[2] == p[3] && p[4] == p[5] &&
            p[0].first == p[2].first && 
            p[0].second == p[4].first && 
            p[2].second == p[4].second) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    
    return 0;
}
