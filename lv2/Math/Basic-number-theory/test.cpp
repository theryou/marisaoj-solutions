#include <bits/stdc++.h>
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + 1LL * rd() % (h - l + 1);
}

bool pr(int n) {
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return n > 1;
}

int main() {
    #define taskname "339"
//    freopen (taskname".inp", "r", stdin);
    freopen (taskname".inp", "w", stdout);
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    int t = 1e9;
    while (!pr(t)) --t;
    cout << 10000 << '\n';
    for (int i = 1; i <= 10000; ++i) {
        cout << Rand(1e8, 1e9) << '\n';
    }
    return 0;
}

