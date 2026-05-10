#include <iostream>
using namespace std;

typedef long long ll;

// 2x2 矩陣乘法
void mul(ll a[2][2], ll b[2][2], ll mod) {
    ll res[2][2] = {0};
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
                
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            a[i][j] = res[i][j];
}

int main() {
    // 優化 I/O 速度
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    ll n, m;
    while (cin >> n >> m) {
        ll mod = 1LL << m; // 相當於 2^m
        
        if (n == 0) { 
            cout << 0 << '\n'; 
            continue; 
        }
        
        // 單位矩陣 (存放解答)
        ll ans[2][2] = {{1, 0}, {0, 1}};
        // 轉移矩陣
        ll base[2][2] = {{1, 1}, {1, 0}};
        
        n -= 1; // 費氏數列的 F(n) 相當於轉移矩陣的 n-1 次方
        
        // 快速冪 (Fast Exponentiation)
        while (n > 0) {
            if (n & 1) mul(ans, base, mod);
            mul(base, base, mod);
            n >>= 1;
        }
        
        // F(n) 位於結果矩陣的 [0][0]
        cout << ans[0][0] % mod << '\n';
    }
    return 0;
}
