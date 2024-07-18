#include <bits/stdc++.h>
using namespace std;

int q;
multiset<int> s;
multiset<int>::iterator it;

int main() {
	ios::sync_with_stdio(false);  cin.tie(nullptr);
	cin >> q;
	for (int type, x; q--; ) {
		cin >> type >> x;
		if (type == 1) {
			s.insert(x);
		} else 
		if (type == 2) {
			if (s.count(x)) s.erase(s.find(x));
		} else 
		if (type == 3) {
			it = s.upper_bound(x);
			if (it != s.end()) cout << *it << '\n';
			else cout << -1 << '\n';
		} else {
			it = s.upper_bound(x);
			if (it != s.begin()) cout << *(--it) << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}