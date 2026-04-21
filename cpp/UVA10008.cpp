//https://zerojudge.tw/ShowProblem?problemid=c044
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
 
bool cmp(pair<int, char> a, pair<int, char> b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <pair<int, char> > v(26);
    for (int i = 0; i < 26; i++) {
        v[i] = {0, 'A'+i};
    }
    int n;
    string s;
    cin >> n;
    getline(cin, s); // clear buffer (\n)
    while (n--) {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                v[s[i] - 'A'].first++;
            }
            if ('a' <= s[i] && s[i] <= 'z') {
                v[s[i] - 'a'].first++;
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i: v) {
        if (i.first > 0) cout << i.second << " " << i.first << "\n";
    }
    return 0;
}
