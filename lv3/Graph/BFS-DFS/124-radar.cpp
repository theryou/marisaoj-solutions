#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;

int n;
long long x[maxn], y[maxn];
queue<int> q;
bool vis[maxn];

bool connected(const long long &x, const long long &y, const long long &u, const long long &v, const double &R) {
	return 4 * R * R - (x - u) * (x - u) - (y - v) * (y - v) >= 0;
}

bool ok(double R) {
	fill(vis, vis + maxn, false);
	q.push(0);
	vis[0] = true;
	int m = n - 1;
	while (q.size()) {
		int u = q.front();
		long long ux = x[u], uy = y[u];	q.pop();
		for (int v = 0; v < n; ++v) if (!vis[v] && connected(ux, uy, x[v], y[v], R)) {
			vis[v] = true;
			--m;
			q.push(v);
		}
	}
	return !m;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	double l = 0, r = 1e10;
	for (int i = 0; i < 100; ++i) {
		double mid = (l + r) / 2;
		if (ok(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(6) << r;
	return 0;
}
