#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int maxn = 3e3 + 1;

int n, m, k;
int u[maxn], v[maxn], p[maxn];
vector<int> E[maxn];
int dl[maxn], dr[maxn];
queue<int> q;

void bfs(int r, int d[maxn]) {
	fill(d, d + maxn, +oo);	d[r] = 0;
	q.push(r);
	while (q.size()) {
		int u = q.front();	q.pop();
		for (int &v_ : E[u]) if (d[v_] == +oo) {
			d[v_] = d[u] + 1;
			q.push(v_);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) cin >> p[i];
	for (int i = 0; i < m; ++i) {
		cin >> u[i] >> v[i];
		E[u[i]].push_back(v[i]);
		E[v[i]].push_back(u[i]);
	}
	long long ans = 1e9 + 7;
	for (int i = 0; i < m; ++i) {
		bfs(u[i], dl);
		bfs(v[i], dr);

		long long total = 0;
		for (int j = 0; j < k; ++j) {
			total += min(dl[p[j]], dr[p[j]]);
		}
		ans = min(total, ans);
	}
	cout << ans;
	return 0;
}
