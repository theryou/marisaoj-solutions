#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m;
vector<int> E[maxn];
int c[maxn];

bool bfs(int r) {
	queue<int> q;	q.push(r);
	c[r] = 1;
	while (q.size()) {
		int u = q.front();	q.pop();
		for (int &v : E[u]) {
			if (!c[v]) {
				c[v] = 3 - c[u];
				q.push(v);
			} else
			if (c[v] == c[u]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) if (!c[i]) {
		if (!bfs(i)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
