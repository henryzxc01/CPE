//https://zerojudge.tw/ShowProblem?problemid=a012
#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n1, n2;
    while (cin >> n1 >> n2){
        cout << abs(n1 - n2) << "\n";
    }
    return 0;
}
