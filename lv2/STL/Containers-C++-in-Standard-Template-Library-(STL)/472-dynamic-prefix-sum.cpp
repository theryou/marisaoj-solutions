#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<long long> a;

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  cin >> n >> q;
  a.resize(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
  	cin >> a[i];
  	a[i] += a[i - 1];
  }
  for (int type, x, y; q--; ) {
  	cin >> type;
  	if (type == 1) {
  		cin >> x;
  		a.push_back(x + a.back());
  	} else 
  	if (type == 2) {
  		a.pop_back();
  	} else {
  		cin >> x >> y;
  		cout << a[y] - a[x - 1] << '\n';
  	}
  }
  return 0;
}