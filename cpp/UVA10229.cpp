#include <iostream>
using namespace std;

typedef long long ll;

// 回傳 pair 包含 {F_n, F_{n+1}}
pair<ll, ll> fast_doubling(ll n, ll mod) {
    if (n == 0) return {0, 1};
    
    // 遞迴計算一半
    pair<ll, ll> p = fast_doubling(n >> 1, mod);
    ll fk = p.first;
    ll fk1 = p.second;
    
    // 套用公式，注意減法取模要加上 mod 避免出現負數
    ll f2k = (fk * ((2 * fk1 - fk) % mod + mod)) % mod;
    ll f2k1 = (fk * fk + fk1 * fk1) % mod;
    
    if (n & 1) // 如果 n 是奇數，則回傳 {F_{2k+1}, F_{2k+2}}
        return {f2k1, (f2k + f2k1) % mod};
    else       // 如果 n 是偶數，則回傳 {F_{2k}, F_{2k+1}}
        return {f2k, f2k1};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    while (cin >> n >> m) {
        if (n == 0) { cout << 0 << '\n'; continue; }
        ll mod = 1LL << m;
        cout << fast_doubling(n, mod).first << '\n';
    }
    return 0;
}
