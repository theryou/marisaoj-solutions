#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;

int n, m;
bool planted[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y];
}

int dfs(int rx, int ry) {
	stack<pair<int, int> > s;
	s.push(make_pair(rx, ry));

	int cnt = planted[rx][ry];
	vis[rx][ry] = true;
	while (s.size()) {
		pair<int, int> u = s.top();	s.pop();
		int ux = u.first, uy = u.second;

		for (int i = 0; i < 4; ++i) {
			int vx = ux + dx[i], vy = uy + dy[i];
			if (!valid(vx, vy)) continue;
			cnt += planted[vx][vy];
			vis[vx][vy] = true;
			s.push(make_pair(vx, vy));
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char x; cin >> x;
			if (x == '#') vis[i][j] = true;
			else
			if (x == 'x') planted[i][j] = true;
			else planted[i][j] = false;
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (!vis[i][j]) {
			int trees = dfs(i, j);
			if (trees) ans.push_back(trees);
		}
	}
	sort(ans.begin(), ans.end());
	for (int &x : ans) cout << x << ' ';
	return 0;
}
