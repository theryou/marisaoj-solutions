#include <bits/stdc++.h>
using namespace std;

set<int> l, r;

void pr(int x) {
	if (x % 2 == 0) cout << x / 2 << '\n';
	else cout << x / 2 << ".5\n";
}

void fix() {
	if ((int) l.size() - (int) r.size() > 1) {
		r.insert(*l.rbegin());
		l.erase(l.find(*l.rbegin()));
	} else 
	if ((int) r.size() - (int) l.size() == 1) {
		l.insert(*r.begin());
		r.erase(r.begin());
	}
}

void solve() {
	int type, x; cin >> type;
	if (type == 1) {
		cin >> x;
		if (l.find(x) != l.end()) {
			l.erase(x);
		} else 
		if (r.find(x) != r.end()) {
			r.erase(x);
		} else {
			if (!l.size() || x < *l.rbegin()) {
				l.insert(x);
			}	else {
				r.insert(x);
			}
		}
		fix();
	} else {
		if ((int) l.size() - r.size() == 1) cout << *l.rbegin() << '\n';
		else pr(*l.rbegin() + *r.begin());
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