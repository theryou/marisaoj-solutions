#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 1;

long long n, x;
long long a[maxn];
map<long long, int> f;

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = n; j > 2; --j) {
        f.clear();
        for (int i = 2; i < j; ++i) {
            f[a[i - 1]] = i - 1;
            if (f[x - a[j] - a[i]]) return cout << f[x - a[j] - a[i]] << ' ' << i << ' ' << j, 0;
        }
    }
    return 0;
}
