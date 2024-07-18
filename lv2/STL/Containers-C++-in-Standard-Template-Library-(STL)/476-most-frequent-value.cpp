#include <bits/stdc++.h>
using namespace std;

map<long long, set<long long> > f;
map<long long, long long> g;
multiset<long long> h;

void update(long long x, long long y) {
	f[g[x]].erase(x);
	if (h.find(g[x]) != h.end()) h.erase(h.find(g[x]));
	g[x] = max(g[x] + y, 0ll);
	f[g[x]].insert(x);
	h.insert(g[x]);
}

void solve() {
	long long type, x, y; cin >> type;
	if (type == 1) {
		cin >> x >> y;
		update(x, y);
	} else 
	if (type == 2) {
		cin >> x >> y;
		update(x, -y);
	} else {
		cout << *(f[*(h.rbegin())].rbegin()) << '\n';
	}
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
  	solve();
  }
  return 0;
}