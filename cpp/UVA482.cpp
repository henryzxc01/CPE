//https://zerojudge.tw/ShowProblem?problemid=e529
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    cin.ignore(); // 忽略第一行後的換行符

    while (cases--) {
        cin.ignore(); // 忽略 case 之間的空行

        string line1, line2, numStr;
        vector<int> idx;
        vector<pair<int, string>> result;

        // 1. 讀取索引 (Index)
        getline(cin, line1);
        stringstream ss1(line1);
        int tempIdx;
        while (ss1 >> tempIdx) {
            idx.push_back(tempIdx);
        }

        // 2. 讀取數值 (Numbers) 並直接與索引配對
        getline(cin, line2);
        stringstream ss2(line2);
        for (int i : idx) {
            ss2 >> numStr;
            result.push_back({i, numStr});
        }

        // 3. 排序 (利用 pair 預設以 first 元素排序的特性)
        sort(result.begin(), result.end());

        // 4. 輸出
        for (auto& p : result) {
            cout << p.second << endl;
        }

        if (cases > 0) cout << endl; // 題目要求 Case 之間要有空行
    }
    return 0;
}
