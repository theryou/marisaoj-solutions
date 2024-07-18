#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long mod) {
    long long ans = 0;
    for ( ; b; b /= 2) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    long long a, b, c; cin >> a >> b >> c;
    cout << mul(a, b, c);
    return 0;
}
