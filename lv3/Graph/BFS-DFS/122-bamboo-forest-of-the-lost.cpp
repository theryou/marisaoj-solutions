#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m, a, b;
vector<int> E[maxn];
int marisa[maxn], reimu[maxn];

void bfs(int r, int d[maxn]) {
	queue<int> q;	q.push(r);
	while (q.size()) {
		int u = q.front();	q.pop();
		for (int &v : E[u]) if (!d[v] && v != r) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m >> a >> b;
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	bfs(a, marisa);
	bfs(b, reimu);
	int ans = 1e9 + 7;
	for (int i = 1; i <= n; ++i) if (marisa[i] == reimu[i]) ans = min(marisa[i], ans);
	if (ans == 1e9 + 7) cout << -1;
	else cout << ans;
	return 0;
}
