//https://zerojudge.tw/ShowProblem?problemid=c012
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 獨立的比較函式：定義排序規則
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) 
        return a.second < b.second; // 規則 1：頻率由小到大
    return a.first > b.first;       // 規則 2：頻率相同時，ASCII 由大到小
}

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    bool first = true;

    // 讀取直到 EOF
    while (getline(cin, s)) {
        if (!first) cout << '\n';
        first = false;

        int freq[128] = {0};
        for (char c : s) {
            freq[(int)c]++;
        }

        vector<pair<int, int>> v;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                v.push_back({i, freq[i]});
            }
        }

        // 將自訂的 cmp 函式作為參數傳入
        sort(v.begin(), v.end(), cmp);

        for (auto p : v) {
            cout << p.first << " " << p.second << '\n';
        }
    }
    return 0;
}
