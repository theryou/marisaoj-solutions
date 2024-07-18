#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

int u, v;
int f[maxn], g[maxn];

void handle(int n, int (&fn)[maxn]) {
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        for ( ; n % i == 0; n /= i) ++fn[i];
    }
    if (n > 1) {
        ++fn[n];
    }
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> u >> v;

    handle(u, f);
    handle(v, g);

    int ans = 1;
    for (int i = 2; i < maxn; ++i) {
        if (f[i] > g[i]) {
            ans = 0;
            break;
        }
        if (f[i] - g[i]) ans *= 2;
    }
    cout << ans;
    return 0;
}
