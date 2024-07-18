#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n;
int a[maxn], cnt[maxn];

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int i = 0, j = -1;
    long long ans = 0;
    while (j < n - 1) {
        ++cnt[a[++j]];
        while (cnt[a[j]] > 1) --cnt[a[i++]];
        ans += j - i + 1;
    }
    cout << ans;
    return 0;
}
