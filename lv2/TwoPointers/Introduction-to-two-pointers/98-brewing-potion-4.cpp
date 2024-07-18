#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m;
int a[maxn], b[maxn], c[maxn];
int ans = 0;

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
	int l = 1, r = 0;
	while (r <= n) {
		++r;
		++c[a[r]];
		while (c[a[r]] > b[a[r]]) {
			--c[a[l]];
			++l;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
