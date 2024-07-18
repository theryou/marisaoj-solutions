#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

int f[maxn], sf[maxn];

void init(int N = maxn - 1) {
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; j += i) ++f[j];
  }
  for (int i = 1; i <= N; ++i) sf[i] = sf[i - 1] + f[i];
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  init();

  int tt; cin >> tt;
  while (tt--) {
    int l, r; cin >> l >> r;
    cout << sf[r] - sf[l - 1] << '\n';
  }
  return 0;
}
