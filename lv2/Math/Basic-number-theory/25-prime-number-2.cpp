#include <bits/stdc++.h>
using namespace std;

string ip(long long x) {
  if (x < 2) return "NO";
  for (long long i = 2; i * i <= x; ++i) if (x % i == 0) return "NO";
  return "YES";
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(nullptr);
  long long n; cin >> n;
  cout << ip(n);
  return 0;
}
