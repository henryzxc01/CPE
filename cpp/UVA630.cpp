//https://zerojudge.tw/ShowProblem?problemid=e608
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        // 儲存原始單字與排序後的單字
        vector<string> words(N), sorted_words(N);
        for (int i = 0; i < N; ++i) {
            cin >> words[i];
            sorted_words[i] = words[i];
            sort(sorted_words[i].begin(), sorted_words[i].end());
        }

        string query;
        while (cin >> query && query != "END") {
            cout << "Anagrams for: " << query << endl;
            
            // 處理查詢單字
            string q_sorted = query;
            sort(q_sorted.begin(), q_sorted.end());

            int count = 0;
            for (int i = 0; i < N; ++i) {
                // 如果排序後相同，即為 Anagram
                if (sorted_words[i] == q_sorted) {
                    cout << "  " << ++count << ") " << words[i] << endl;
                }
            }

            if (count == 0) {
                cout << "No anagrams for: " << query << endl;
            }
        }
        
        // 測資間的空行 (UVA 格式要求)
        if (T) cout << endl;
    }
    return 0;
}
