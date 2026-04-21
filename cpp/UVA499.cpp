//https://zerojudge.tw/ShowProblem?problemid=e503
#include <iostream>
#include <map>
using namespace std;
 
int main() {
    string s;
    while (getline(cin, s)){
        map <char,int> mp;
        int mx = 0;
        for (int i = 0; i < s.size(); i++){
            if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')){
                mp[s[i]]++;
                mx = max(mx, mp[s[i]]);
            }
        }
        for (auto i: mp){
            if (i.second == mx) cout << i.first;
        }
        cout << " " << mx << "\n";
    }
    return 0;
}
