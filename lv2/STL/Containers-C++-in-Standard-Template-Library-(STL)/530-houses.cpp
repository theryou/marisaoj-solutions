#include <bits/stdc++.h>
using namespace std;

set<int> s;
multiset<int> d;

void solve() {
	int x; cin >> x;
	if (s.count(x)) {
		set<int>::iterator i = s.lower_bound(x), l = i, r = i;
		--l; ++r;
		if (r != s.end()) {
			d.erase(d.find(*r - x));
		}
		if (i != s.begin()) {
			d.erase(d.find(x - *l));
		}
		s.erase(x);
	} else {
		s.insert(x);
		set<int>::iterator i = s.lower_bound(x), l = i, r = i;
		--l; ++r;
		if (r != s.end()) {
			d.insert(*r - x);
		}
		if (i != s.begin()) {
			d.insert(x - *l);
		}
	}
	if (s.size() > 1) cout << *d.begin() << '\n';
	else cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  int n; cin >> n;
  while (n--) {
  	solve();
  }
  return 0;
}