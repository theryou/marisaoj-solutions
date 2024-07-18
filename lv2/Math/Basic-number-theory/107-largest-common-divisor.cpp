#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 1;

set<int> f;
int e[maxn];

long long power(long long a, int b) {
  long long c = 1;
  for ( ; b; b /= 2) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
  }
  return c;
}

void handle(int n) {
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
    int exp = 0;
    while (n % i == 0) {
      ++exp;
      n /= i;
    }

    f.insert(i);
    e[i] = max(exp, e[i]);
  }
  if (n > 1) {
    f.insert(n);
    e[n] = max(1, e[n]);
  }
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  int n; cin >> n;
  for (int x, i = 0; i < n; ++i) {
    cin >> x;
    handle(x);
  }

  long long ans = 1;
  for (set<int>::iterator i = f.begin(); i != f.end(); ++i) {
    ans = (ans * power(*i, e[*i])) % mod;
  }
  cout << ans;
  return 0;
}
