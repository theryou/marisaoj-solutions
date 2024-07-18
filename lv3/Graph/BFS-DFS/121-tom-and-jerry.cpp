#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int maxn = 1e5 + 1;

int n, m, a, b;
vector<int> E[maxn];
int jerry[maxn], tom[maxn];
bool vis[maxn];

void bfs(int r, int d[maxn]) {
	fill(d, d + maxn, +oo);	d[r] = 0;
	fill(vis, vis + maxn, false);	vis[r] = true;
	queue<int> q;	q.push(r);

	while (q.size()) {
		int u = q.front();	q.pop();
		for (int &v : E[u]) if (!vis[v]) {
			vis[v] = true;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	cin >> a >> b;
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	bfs(b, tom);	bfs(a, jerry);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) if (vis[i] && jerry[i] <= tom[i]) ++cnt;
	cout << cnt;
	return 0;
}
