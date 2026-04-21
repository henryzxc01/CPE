//https://zerojudge.tw/ShowProblem?problemid=a743
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // 加速 I/O，競賽常用技巧
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> counts;
    string country, rest_of_line;

    while (n--) {
        cin >> country;           // 讀取第一個單字 (國家)
        getline(cin, rest_of_line); // 讀掉這行剩下的部分 (名字，不重要)
        counts[country]++;        // 該國家計數 +1
    }

    // 輸出結果，map 已經依照 Key (國家名稱) 自動排好序了
    for (auto i: counts) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}
