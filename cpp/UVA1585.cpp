#include <iostream>
using namespace std;
 
int main() {
    int T;
    string s;
    cin >> T;
    while (T--){
        cin >> s;
        int cnt = 0; //連續的"O"個數
        int sum = 0; //累計分數
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'O'){
                cnt ++;
                sum += cnt;
            } else {
                cnt = 0;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
