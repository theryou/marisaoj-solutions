#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m;
vector<int> e[maxn];
bool vis[maxn];

void dfs(int r) {
	stack<int> s;
	s.push(r);
	while (s.size()) {
		int u = s.top();	s.pop();
		if (vis[u]) continue;
		else vis[u] = true;
		for (int &v : e[u]) if (!vis[v]) {
			s.push(v);
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

	int ans = 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		++ans;
		dfs(i);
	}
	cout << ans;
	return 0;
}
