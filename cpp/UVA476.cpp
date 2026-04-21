https://zerojudge.tw/ShowProblem?problemid=d091
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 優化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    struct Rect { double x1, y1, x2, y2; };
    vector<Rect> figs;
    char type;
    double rx1, ry1, rx2, ry2;

    // 1. 讀取矩形資料 (直到讀到 '*')
    while (cin >> type && type != '*') {
        cin >> rx1 >> ry1 >> rx2 >> ry2;
        figs.push_back({rx1, ry1, rx2, ry2});
    }

    double px, py;
    int p_id = 1;

    // 2. 讀取點資料 (直到讀到 9999.9 9999.9)
    while (cin >> px >> py && (px != 9999.9 || py != 9999.9)) {
        bool contained = false;
        
        // 遍歷所有矩形檢查
        for (int i = 0; i < figs.size(); i++) {
            // 檢查是否在範圍內 (注意：題目要求嚴格小於/大於，不含邊界)
            // 題目給的是左上 (x1, y1) 和右下 (x2, y2)，所以 y2 是較小值，y1 是較大值
            if (px > figs[i].x1 && px < figs[i].x2 && 
                py < figs[i].y1 && py > figs[i].y2) {
                cout << "Point " << p_id << " is contained in figure " << i + 1 << "\n";
                contained = true;
            }
        }

        if (!contained) {
            cout << "Point " << p_id << " is not contained in any figure\n";
        }
        p_id++;
    }

    return 0;
}
