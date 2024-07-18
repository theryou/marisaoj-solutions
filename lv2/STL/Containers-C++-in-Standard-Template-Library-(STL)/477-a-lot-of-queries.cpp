#include <bits/stdc++.h>
using namespace std;

map<int, long long> f;
set<int> s;

void update(int x, int y) {
	s.erase(x);
	f[x] = max(f[x] + y, 0ll);
	if (f[x]) s.insert(x);
}

void solve() {
	int type, x, y; cin >> type;
	if (type == 1) {
		cin >> x >> y;
		update(x, y);
	} else 
	if (type == 2) {
		cin >> x >> y;
		update(x, -y);
	} else 
	if (type == 3) {
		cout << *(s.begin()) << '\n';
	} else 
	if (type == 4) {
		cout << *(s.rbegin()) << '\n';
	} else {
		cin >> y;
		long long sum = 0;
		if (s.size()) {
			for (set<int>::iterator p = s.upper_bound(y); ; --p) if (p != s.end()) {
				sum += (*p) * (f[*p]);
				if ((*p) < y || p == s.begin()) break;
			}
		}
		cout << sum << '\n';
	}
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}