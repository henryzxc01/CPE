//https://zerojudge.tw/ShowProblem?problemid=e510
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int S, N, K;
    double p;
    cin >> S;
    while (S--){
        cin >> N >> p >> K;
        if (p == 0) {
            cout << "0.0000\n";
            continue;
        }
        double first = pow(1.0 - p, K-1) * p;
        double r = pow(1.0 - p, N);
        cout << fixed << setprecision(4) <<
        first / (1.0 - r) << "\n";
    }
    return 0;
}
