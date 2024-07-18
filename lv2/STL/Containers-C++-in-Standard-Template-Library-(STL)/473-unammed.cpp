#include <bits/stdc++.h>
using namespace std;

int n, x;
map<int, int> f;

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  cin >> n >> x;
  for (int a, i = 1; i <= n; ++i) {
  	cin >> a;
  	++f[a];
  }

  long long ans = 0;
  for (int b, i = 1; i <= n; ++i) {
  	cin >> b;
  	ans += f[x - b];
  }
  cout << ans;
  return 0;
}