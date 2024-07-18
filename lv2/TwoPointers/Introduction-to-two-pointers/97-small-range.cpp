#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, k;
int a[maxn];
deque<int> mx, mn;

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 1, r = 0;
    long long ans = 0;
    while (r < n) {
        ++r;

        while (mx.size() && a[mx.back()] < a[r]) mx.pop_back();
        mx.push_back(r);
        while (mn.size() && a[mn.back()] > a[r]) mn.pop_back();
        mn.push_back(r);

        while (mx.size() && mn.size() && a[mx.front()] - a[mn.front()] > k) {
            ++l;
            while (mx.size() && mx.front() < l) mx.pop_front();
            while (mn.size() && mn.front() < l) mn.pop_front();
        }

        ans += r - l + 1;
    }
    cout << ans;
    return 0;
}
