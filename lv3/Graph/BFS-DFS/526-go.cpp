#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 1;

int n, m;
string a[maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[maxn][maxn];

bool valid(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y];
}

int bfs(pair<int, int> r) {
	int cnt = 0;
	bool ok = true;
	queue<pair<int, int> > q;	q.push(r);
	vis[r.first][r.second] = true;
	while (q.size()) {
		pair<int, int> u = q.front();	q.pop();
		if (ok && a[u.first][u.second] == 'W') ++cnt;
		else ok = false;
		for (int i = 0; i < 4; ++i) {
			int vx = u.first + dx[i],	vy = u.second + dy[i];
			if (!valid(vx, vy)) continue;
			vis[vx][vy] = true;
			q.push(make_pair(vx, vy));
		}
	}
	if (ok)	return cnt;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = ' ' + a[i];
		for (int j = 1; j <= m; ++j) if (a[i][j] == 'B') {
			vis[i][j] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (!vis[i][j] && a[i][j] == 'W') {
			ans += bfs(make_pair(i, j));
		}
	}
	cout << ans;
	return 0;
}
