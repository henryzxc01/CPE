//https://zerojudge.tw/ShowProblem?problemid=a737
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, r;
    cin >> T;
    while (T--) {
        cin >> r;
        int s[r];
        for (int i = 0; i < r; i++){
            cin >> s[i];
        }
        sort(s, s+r);
        int sum = 0;
        for (int i = 0; i < r; i++){
            sum += abs(s[i] - s[r/2]);
        }
        cout << sum << "\n";
    }
    return 0;
}
