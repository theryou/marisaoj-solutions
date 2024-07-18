#include <bits/stdc++.h>
using namespace std;

void fact(int n) {
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
    cout << i << ' ';
    while (n % i == 0) n /= i;
  }
  if (n > 1) cout << n;
  cout << '\n';
}

void solve() {
  int n;  cin >> n;
  fact(n);
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
