#include <bits/stdc++.h>
using namespace std;

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
    long long a, b, c; cin >> a >> b >> c;
    cout << power(a, b, c);
    return 0;
}
