#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int maxn = 1e6 + 1;

int n;
vector<int> f[maxn], p[maxn];

void addFac(int fac, int pos) {
	f[pos].push_back(fac);
	p[fac].push_back(pos);
}

void update(int &j, int i, int p) {
	if (p != i && abs(p - i) < abs(j - i)) j = p;
	if (abs(p - i) == abs(j - i)) j = min(p, j);
}

void handle(int x, int pos) {
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
		addFac(i, pos);
		while (x % i == 0) x /= i;
	}
	if (x > 1) addFac(x, pos);
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	for (int i = 1; i < maxn; ++i) p[i].push_back(-oo);
	cin >> n;
	for (int x, i = 1; i <= n; ++i) {
		cin >> x;
		handle(x, i);
	}
	for (int i = 2; i < maxn; ++i) p[i].push_back(+oo);
		for (int i = 1; i <= n; ++i) {
		int j = +oo;
		for (int &k : f[i]) {
			int l = lower_bound(p[k].begin(), p[k].end(), i) - p[k].begin() - 1, r = l + 2;
			for (int t = l; t <= r; ++t) update(j, i, p[k][t]);
		}
		if (j == +oo || j == -oo) cout << -1 << ' ';
		else cout << j << ' ';
	}
	return 0;
}
