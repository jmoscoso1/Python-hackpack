#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

const int MAXN = 1e6;
const int mod = 1e9 + 7;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	vl fac(MAXN + 1, 1), inv(MAXN + 1, 1);
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
	inv[MAXN] = modpow(fac[MAXN], mod - 2);
	for (int i = MAXN; i >= 1; i--) {
		inv[i - 1] = (inv[i] * i) % mod;
	}
	auto nCr = [&] (int n, int r) {
		if (r > n) return 0LL;
		return fac[n] * inv[r] % mod * inv[n - r] % mod;
	};
}
