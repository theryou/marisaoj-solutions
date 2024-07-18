#include <bits/stdc++.h>
using namespace std;

int n, q;
map<int, vector<int> > f;

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  cin >> n >> q;
  for (int x, i = 1; i <= n; ++i) {
  	cin >> x;
  	f[x].push_back(i);
  }
  for (int x, k; q--; ) {
  	cin >> x >> k;
  	cout << f[x][k - 1] << '\n';
  }
  return 0;
}