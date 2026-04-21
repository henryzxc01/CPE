//https://zerojudge.tw/ShowProblem?problemid=e579
#include <iostream>
#include <cstring>
using namespace std;
 
int main() {
    int T, N, P, h;
    cin >> T;
    while (T--){
        cin >> N >> P;
        int a[N+1];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < P; i++){
            cin >> h;
            for (int j = h; j <= N; j+=h){
                a[j] = 1;
            }
        }
        for (int i = 6; i <= N; i+=7){
            a[i] = 0;
        }
        for (int i = 7; i <= N; i+=7){
            a[i] = 0;
        }
        int sum = 0;
        for (int i = 1; i <= N; i++){
            sum += a[i];
        }
        cout << sum << "\n";
    }
    return 0;
}
