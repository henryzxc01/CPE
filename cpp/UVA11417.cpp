#include <iostream>
#include <algorithm> // for __gcd

using namespace std;

int main() {
    // 優化 I/O (非必要但為競賽好習慣)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        int G = 0;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += __gcd(i, j);
            }
        }
        cout << G << "\n";
    }
    return 0;
}
