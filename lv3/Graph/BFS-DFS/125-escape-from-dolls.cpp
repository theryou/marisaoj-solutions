#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m, k;
int doll[maxn];
vector<int> E[maxn];
int d[maxn];

void bfs(int r) {
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
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) cin >> doll[i];
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	bfs(n);
	int cnt = 0;
	for (int i = 0; i < k; ++i) {
		cnt += (d[doll[i]] <= d[1]);
	}
	cout << cnt;
	return 0;
}
