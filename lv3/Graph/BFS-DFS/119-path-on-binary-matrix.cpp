#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;

int n, m;
bool blocked[maxn][maxn];
int dx[] = {-1, 0, 1,  0};
int dy[] = { 0, 1, 0, -1};
int d[maxn][maxn];
bool vis[maxn][maxn];

bool valid(pair<int, int> v) {
	return !blocked[v.first][v.second] && 1 <= v.first && v.first <= n && 1 <= v.second && v.second <= m;
}

void bfs(pair<int, int> r) {
	deque<pair<int, int> > q;	q.push_back(r);
	vis[r.first][r.second] = true;
	d[r.first][r.second] = 0;

	while (q.size()) {
		pair<int, int> u = q.front();	q.pop_front();

		for (int i = 0; i < 4; ++i) {
			pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);
			if (valid(v)) {
				q.push_back(v);
				blocked[v.first][v.second] = true;
				d[v.first][v.second] = d[u.first][u.second] + 1;
				if (v.first == n && v.second == m) return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char x;	cin >> x;
			blocked[i][j] = x - '0';
		}
	}
	bfs(make_pair(1, 1));
	cout << d[n][m];
	return 0;
}
