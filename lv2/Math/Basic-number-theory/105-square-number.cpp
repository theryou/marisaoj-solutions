#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

int n, f[maxn];
long long ans = 0;

void handle(int x, int pos) {
    int base = 1;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
        int d = 0;
        for ( ; x % i == 0; x /= i) ++d;
        if (d & 1) base *= i;
    }
    if (x > 1) base *= x;
    ans += f[base]++;
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n;
    for (int x, i = 1; i <= n; ++i) {
        cin >> x;
        handle(x, i);
    }
    cout << ans;
    return 0;
}
