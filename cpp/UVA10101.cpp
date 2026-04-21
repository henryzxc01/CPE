//https://zerojudge.tw/ShowProblem?problemid=a741
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 競賽常用的 I/O 加速
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    int t = 1;
    // 將對應的數值與字串建表
    long long d[] = {10000000, 100000, 1000, 100};
    string s[] = {" kuti", " lakh", " hajar", " shata"};
    
    while (cin >> n) {
        cout << setw(4) << t++ << ".";
        
        if (n == 0) {
            cout << " 0\n";
            continue;
        }
        
        long long H = n / 10000000; // 高位部分 (大於等於 kuti)
        long long L = n % 10000000; // 低位部分 (小於 kuti)
        
        // 處理高位部分
        if (H > 0) {
            for (int i = 0; i < 4; i++) {
                if (H >= d[i]) {
                    cout << " " << H / d[i] << s[i];
                    H %= d[i];
                }
            }
            if (H > 0) cout << " " << H;
            cout << " kuti"; // 高位處理完必定要補上 kuti 單位
        }
        
        // 處理低位部分
        for (int i = 0; i < 4; i++) {
            if (L >= d[i]) {
                cout << " " << L / d[i] << s[i];
                L %= d[i];
            }
        }
        if (L > 0) cout << " " << L;
        
        cout << "\n";
    }
    return 0;
}
