//https://zerojudge.tw/ShowProblem?problemid=f439
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d = 1;
    // 不斷讀取直到 EOF
    while (cin >> n) {
        // 預設加入 10:00 (600) 與 18:00 (1080) 的邊界值
        vector<pair<int, int>> a = {{600, 600}, {1080, 1080}};
        
        for (int i = 0, h1, m1, h2, m2; i < n; ++i) {
            char c; 
            // 競賽常用的小技巧：利用 char 吸掉 ':' 符號
            cin >> h1 >> c >> m1 >> h2 >> c >> m2;
            a.push_back({h1 * 60 + m1, h2 * 60 + m2});
            
            // 處理掉該行剩下的字串 (備忘錄文字)
            string s; 
            getline(cin, s);
        }
        
        // 依據 pair 的 first (開始時間) 自動進行遞增排序
        sort(a.begin(), a.end());
        
        int ans = 0, st = 0, last = 600;
        for (auto x : a) {
            // 如果當前行程開始時間 - 上一個行程結束時間 > 目前最長午睡
            if (x.first - last > ans) {
                ans = x.first - (st = last); // 更新最大時間與起始點
            }
            // 更新目前出現過最晚的結束時間
            last = max(last, x.second);
        }
        
        // 依據題目要求的格式輸出
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ", d++, st / 60, st % 60);
        if (ans >= 60) {
            printf("%d hours and ", ans / 60);
        }
        printf("%d minutes.\n", ans % 60);
    }
    return 0;
}
