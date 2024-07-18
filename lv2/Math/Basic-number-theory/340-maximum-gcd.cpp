#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

int n;
int a[maxn], cnt[maxn];

void sieve(int N = maxn - 1) {
  cnt[1] = n;
  for (int i = 2; i <= N; ++i) {
    for (int j = i; j <= N; j += i) cnt[i] += a[j];
  }
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  cin >> n;
  for (int x, i = 1; i <= n; ++i) {
    cin >> x;
    ++a[x];
  }

  sieve();

  for (int i = maxn - 1; i > 0; --i) if (cnt[i] > 1) {
    cout << i;
    break;
  }
  return 0;
}
