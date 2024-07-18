#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m;
vector<pair<int, int> > E[maxn];
int d[maxn];
pair<int, int> tr[maxn];

void bfs(int r) {
	queue<int> q;	q.push(r);
	while (q.size()) {
		int u = q.front();	q.pop();
		for (pair<int, int> &e : E[u]) if (!d[e.second] && e.second != r) {
			d[e.second] = d[u] + 1;
			tr[e.second] = make_pair(u, e.first);
			q.push(e.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int u, v, w, i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		E[u].push_back(make_pair(w, v));
		E[v].push_back(make_pair(w, u));
	}
	for (int u = 1; u <= n; ++u) {
		sort(E[u].begin(), E[u].end());
	}
	bfs(1);
	vector<int> path;
	while (n != 1) {
		path.push_back(tr[n].second);
		n = tr[n].first;
	}
	reverse(path.begin(), path.end());
	cout << path.size() << '\n';
	for (int &x : path) cout << x << ' ';
	return 0;
}
