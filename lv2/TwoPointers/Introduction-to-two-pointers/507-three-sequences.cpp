#include <bits/stdc++.h>
using namespace std;

#define mx(a, b, c) max(max(a, b), c)
#define mn(a, b, c) min(min(a, b), c)

const int maxn = 1e5 + 1;

int n;
long long A[maxn], B[maxn], C[maxn];

long long calc(long long a, long long b, long long c) {
  return 2 * (mx(a, b, c) - mn(a, b, c));
}

long long ans(long long (&a)[], long long (&b)[], long long (&c)[]) {
  long long ans = 3e9 + 1;
  int j = 1, k = 1;
  for (int i = 1; i <= n; ++i) {
    while (j + 1 <= n && b[j + 1] <= a[i]) ++j;
    while (k + 1 <= n && c[k + 1] <= a[i]) ++k;

    ans = min(ans, calc(a[i], b[j], c[k]));
  }
  return ans;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> A[i];
	for (int i = 1; i <= n; ++i) cin >> B[i];
	for (int i = 1; i <= n; ++i) cin >> C[i];

  sort(A + 1, A + n + 1);
  sort(B + 1, B + n + 1);
  sort(C + 1, C + n + 1);

  cout << mn(ans(A, B, C), ans(B, A, C), ans(C, A, B));
	return 0;
}
