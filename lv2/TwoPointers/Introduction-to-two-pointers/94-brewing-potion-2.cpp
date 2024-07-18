#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, k;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = 1;
    int ans = 0;
    while (r <= n) {
        while (r <= n && a[r] - a[l] <= k) ++r;
        ans = max(ans, r - l);
        ++l;
    }
    cout << ans;
    return 0;
}
