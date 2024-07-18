#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int maxn = 1e5 + 1;

int n, m;
vector<int> e[maxn];
int d[maxn];

void dijkstra(int r) {
	fill(d, d + maxn, +oo);	d[r] = 0;
	priority_queue<pair<int, int> > q;	q.push(make_pair(0, r));

	while (q.size()) {
		int u = q.top().second, du = -q.top().first;
		q.pop();
		if (du != d[u]) continue;

		for (int &v : e[u]) if (d[v] > du + 1) {
			d[v] = du + 1;
			q.push(make_pair(-d[v], v));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dijkstra(1);
	for (int i = 2; i <= n; ++i)
		if (d[i] != +oo) cout << d[i] << ' ';
		else cout << -1 << ' ';
	return 0;
}
