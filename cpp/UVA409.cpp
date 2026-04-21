//https://zerojudge.tw/ShowProblem?problemid=c114
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype> //isalpha()
#include <algorithm>

using namespace std;

int main() {
    int K, E, setNum = 0;
    while (cin >> K >> E) {
        vector<string> keys(K);
        for (int i = 0; i < K; ++i) cin >> keys[i];
        
        // 吃掉 cin >> E 後的換行符
        string dummy; getline(cin, dummy); 

        vector<string> excuses(E);
        vector<int> counts(E, 0);
        int maxOcc = 0;

        for (int i = 0; i < E; ++i) {
            getline(cin, excuses[i]);
            
            // 處理字串：轉小寫，非字母變空格
            string temp = excuses[i];
            for (char &c : temp) {
                if (isalpha(c)) c = tolower(c);
                else c = ' ';
            }

            // 利用 stringstream 切割單字並比對
            stringstream ss(temp);
            string word;
            while (ss >> word) {
                for (const string &k : keys) {
                    if (word == k) counts[i]++;
                }
            }
            if (counts[i] > maxOcc) maxOcc = counts[i];
        }

        cout << "Excuse Set #" << ++setNum << endl;
        for (int i = 0; i < E; ++i) {
            if (counts[i] == maxOcc) {
                cout << excuses[i] << endl;
            }
        }
        cout << endl; // 每個測資後需空一行
    }
    return 0;
}
