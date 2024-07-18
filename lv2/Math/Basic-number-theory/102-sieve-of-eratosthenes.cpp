#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 1;

bool np[maxn];

void sieve(int N = maxn - 1) {
  for (int i = 2; i * i <= N; ++i) if (!np[i]) {
    for (int j = i * i; j <= N; j += i) np[j] = true;
  }
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  sieve();
  int n; cin >> n;
  for (int i = 2; i <= n; ++i) if (!np[i]) cout << i << ' ';
  return 0;
}
