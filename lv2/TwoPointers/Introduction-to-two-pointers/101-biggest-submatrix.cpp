#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 1;

int n, m, k;
int a[maxn][maxn];

int get(int x, int y, int u, int v) {
  return a[u][v] - a[u][y - 1] - a[x - 1][v] + a[x - 1][y -1];
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char x; cin >> x;
      if (x == '1') a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + 1;
      else a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      for (int s = 0, l = 1, r = 0; l <= m; ++l) {
        while (r + 1 <= m && s + get(i, r + 1, j, r + 1) <= k) {
          ++r;
          s += get(i, r, j, r);
        }
        ans = max(ans, (j - i + 1) * (r - l + 1));
        // cout << i << ' ' << j << ' ' << l << ' ' << r << ' ' << s << ' ' << ans << '\n';
        s -= get(i, l, j, l);
      }
    }
  }
  cout << ans;
  return 0;
}
