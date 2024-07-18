#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int maxn = 1e5 + 1;

int n, m;
vector<int> E[maxn];
int d[maxn], tr[maxn];

void dijkstra(int r) {
	fill(d, d + maxn, +oo);	d[r] = 0;
	priority_queue<pair<int, int> > q;	q.push(make_pair(0, r));

	while (q.size()) {
		int u = q.top().second, du = -q.top().first;
		q.pop();
		if (du != d[u]) continue;

		for (int &v : E[u]) if (d[v] > du + 1) {
			d[v] = du + 1;
			tr[v] = u;
			q.push(make_pair(-d[v], v));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dijkstra(1);

	cout << d[n] << '\n';
	vector<int> path;
	while (n != 0) {
		path.push_back(n);
		n = tr[n];
	}
	reverse(path.begin(), path.end());
	for (int &x : path) cout << x << ' ';
	return 0;
}
