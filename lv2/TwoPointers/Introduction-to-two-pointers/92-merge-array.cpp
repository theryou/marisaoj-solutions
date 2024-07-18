#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> c;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j++]);
        }
    }
    while (i < n) c.push_back(a[i++]);
    while (j < n) c.push_back(b[j++]);
    for (int i = 0; i < 2 * n; ++i) cout << c[i] << ' ';
    return 0;
}
