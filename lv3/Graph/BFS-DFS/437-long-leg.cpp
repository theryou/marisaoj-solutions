#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
const int maxk = 1e1 + 1;

int n, m, k;
vector<int> E[maxn];
bool vis[maxn * maxk];

void bfs(int r) {
	queue<pair<int, int> > q;	q.push(make_pair(r, 0));
	vis[r * k] = true;
	while (q.size()) {
		int u = q.front().first, du = q.front().second;	q.pop();
		if (u == n && du % k == 0) return void(cout << du / k);
		for (int &v : E[u]) if (!vis[v * k + (du + 1) % k]) {
			vis[v * k + (du + 1) % k] = true;
			q.push(make_pair(v, du + 1));
		}
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	bfs(1);
	return 0;
}
