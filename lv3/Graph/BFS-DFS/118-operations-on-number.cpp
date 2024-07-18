#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m;
int d[maxn];

void dfs(int r) {
	stack<int> s;	s.push(r);

	while (s.size()) {
		int u = s.top();	s.pop();

		if (u + 1 < maxn && !d[u + 1]) {
			d[u + 1] = d[u] + 1;
			s.push(u + 1);
		}
		if (u % 2 == 0 && !d[u / 2]) {
			d[u / 2] = d[u] + 1;
			s.push(u / 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n >> m;
	dfs(m);
	cout << d[n];
	return 0;
}
