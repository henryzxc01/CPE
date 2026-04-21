//https://zerojudge.tw/ShowProblem?problemid=d089
#include <bits/stdc++.h>
using namespace std;

// 費率表：對應 A-E (0-4)，分別為 Day, Eve, Night
double r[5][3] = {
    {0.10, 0.06, 0.02},
    {0.25, 0.15, 0.05},
    {0.53, 0.33, 0.13},
    {0.87, 0.47, 0.17},
    {1.44, 0.80, 0.30}
};

int main() {
    char type;
    string num;
    int h1, m1, h2, m2;

    // 讀取輸入，直到 '#' 結束
    while (cin >> type && type != '#') {
        cin >> num >> h1 >> m1 >> h2 >> m2;

        int start = h1 * 60 + m1;
        int end = h2 * 60 + m2;
        // 若結束時間小於等於開始時間，代表跨日，加上 24 小時 (1440分)
        if (end <= start) end += 1440;

        int cnt[3] = {0}; // 紀錄 Day, Eve, Night 的分鐘數
        
        // 分鐘模擬法：直接跑迴圈計算每一分鐘落在哪個區間
        for (int i = start; i < end; i++) {
            int t = i % 1440; // 取餘數處理跨日對應的時間點
            if (t >= 480 && t < 1080) cnt[0]++;      // 08:00 (480) - 18:00 (1080)
            else if (t >= 1080 && t < 1320) cnt[1]++; // 18:00 (1080) - 22:00 (1320)
            else cnt[2]++;                           // 其餘為 Night
        }

        double total = cnt[0] * r[type - 'A'][0] + 
                       cnt[1] * r[type - 'A'][1] + 
                       cnt[2] * r[type - 'A'][2];

        // 依照題目嚴格格式輸出
        printf("%10s%6d%6d%6d%3c%8.2lf\n", num.c_str(), cnt[0], cnt[1], cnt[2], type, total);
    }
    return 0;
}
