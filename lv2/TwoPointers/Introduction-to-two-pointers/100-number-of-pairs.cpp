#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, x;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int i = 1, j = n;
    int cnt = 0;
    while (i < j) {
        if (a[i] + a[j] == x) {
            ++cnt;
            --j;
            ++i;
        }
        while (i < j && a[i] + a[j] < x) ++i;
        while (i < j && a[i] + a[j] > x) --j;
    }
    cout << cnt;
    return 0;
}
