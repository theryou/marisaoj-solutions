#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7 + 1;

bool np[mx];
vector<int> p;

void sieve(int N = mx - 1) {
	for (int i = 2; i * i <= N; ++i) if (!np[i]) {
		for (int j = i * i; j <= N; j += i) np[j] = true;
	}
	np[1] = true;
	for (int i = 2; i <= N; ++i) if (!np[i]) {
        p.push_back(i);
	}
}

bool ip(int n) {
	if (n < mx) return !np[n];
	for (int &i : p) {
		if (i * i > n) break;
		if (n % i == 0) return false;
	}
	return true;
}

void solve() {
	int n; cin >> n;

	int ans = 1;
	if (ip(n)) {
        ans = 2;
        n = 1;
	}
	for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        int d = 0;
        while (n % i == 0) {
            n /= i;
            ++d;
        }
        ans *= (d + 1);

        if (ip(n)) {
            ans *= 2;
            n = 1;
        }
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(nullptr);
	sieve();
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
