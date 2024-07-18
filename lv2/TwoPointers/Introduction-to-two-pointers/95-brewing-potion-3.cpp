#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, k;
int a[maxn], f[maxn], ans = 0;

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = 0;
    while (l <= n) {
        while (r + 1 <= n && a[r + 1] - a[l] <= k) {
            ++r;
            f[r] = f[r - 1];
            f[r] = max(f[r], r - l + 1);
            ans = max(ans, r - l + 1 + f[l - 1]);
        }
        ++l;
    }
    cout << ans;
    return 0;
}
