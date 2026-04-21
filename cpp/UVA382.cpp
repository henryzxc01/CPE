//https://zerojudge.tw/ShowProblem?problemid=c032
#include <iostream>
#include <iomanip> // 必須引入，為了使用 setw
using namespace std;

int main() {
    cout << "PERFECTION OUTPUT" << endl;

    int n;
    while (cin >> n && n != 0) {
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (n % i == 0) sum += i;
        }

        // setw(5) 設定下一個輸出的寬度為 5 (預設靠右)
        cout << setw(5) << n << "  ";

        if (sum == n) cout << "PERFECT" << endl;
        else if (sum < n) cout << "DEFICIENT" << endl;
        else cout << "ABUNDANT" << endl;
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}
