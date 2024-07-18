#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> a;

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  cin >> n >> q;
  a.resize(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int type, value; q--; ) {
  	cin >> type;
  	if (type == 1) {
  		cin >> value;
  		a.push_back(value);
  	} else 
  	if (type == 2) {
  		a.pop_back();
  	} else {
  		cin >> value;
  		cout << a[value] << '\n';
  	}
  }
  return 0;
}