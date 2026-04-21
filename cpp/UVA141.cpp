//https://vjudge.net/problem/UVA-141
#include <iostream>
#include <set>

using namespace std;

// 將盤面定義為 alias，簡化後續的宣告
using State = set<pair<int, int>>;

// 輔助函數：將整個盤面順時針旋轉 90 度
State rotate_board(const State& s, int n) {
    State res;
    // 座標轉換公式：(r, c) -> (c, n - r + 1)
    for (auto p : s) {
        res.insert({p.second, n - p.first + 1});
    }
    return res;
}

int main() {
    // 關閉同步，加速 I/O
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    while (cin >> n && n) {
        set<State> hist;
        State board;
        hist.insert(board); // 初始空盤也是一種歷史狀態
        
        int winner = 0, move = 0;
        
        // 遊戲上限為 2 * n 步
        for (int i = 1; i <= 2 * n; ++i) {
            int r, c; char op;
            cin >> r >> c >> op;
            
            // 若已分出勝負，則純讀取剩餘測資，不處理
            if (winner) continue; 
            
            if (op == '+') board.insert({r, c});
            else board.erase({r, c});
            
            // 只要當前盤面曾出現在歷史中 (含之前盤面的各種旋轉)，即判輸
            if (hist.count(board)) {
                winner = (i % 2 == 1) ? 2 : 1; // 奇數步是 Player 1，偶數步是 Player 2
                move = i;
            } else {
                // 將當前盤面及其 3 種旋轉型態全數加入歷史紀錄
                State temp = board;
                for (int j = 0; j < 4; ++j) {
                    hist.insert(temp);
                    temp = rotate_board(temp, n);
                }
            }
        }
        
        if (winner) cout << "Player " << winner << " wins on move " << move << "\n";
        else cout << "Draw\n";
    }
    
    return 0;
}
