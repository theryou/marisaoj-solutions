#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

bool np[maxn];

void sieve(long long l, long long r) {
  long long sqrtr = sqrt(r);
  vector<bool> ip(sqrtr + 1, true);
  vector<long long> primes;
  for (long long i = 2; i <= sqrtr; ++i) if (ip[i]) {
    primes.push_back(i);
    for (long long j = i * i; j <= sqrtr; j += i) ip[j] = false;
  }

  for (long long &p : primes) {
    for (long long j = max(p * p, (l + p - 1) / p * p); j <= r; j += p) 
      np[j - l] = true;
  }
  if (l == 1) np[0] = true;
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  long long l, r; cin >> l >> r;
  sieve(l, r);
  for (long long i = l; i <= r; ++i) if (!np[i - l]) cout << i << ' ';
  return 0;
}
