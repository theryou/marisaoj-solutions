#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long mul(long long a, long long b, long long c) {
    long long ans = 0;
    for ( ; b; b /= 2) {
        if (b & 1) ans = (ans + a) % c;
        a = (a + a) % c;
    }
    return ans;
}

long long power(long long a, long long b, long long c) {
    long long ans = 1;
    for ( ; b; b /= 2) {
        if (b & 1) ans = mul(ans, a, c);
        a = mul(a, a, c);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    long long n; cin >> n;
    cout << mul(power(3, n - (n / 3), mod), power(4, n / 3, mod), mod);
    return 0;
}
