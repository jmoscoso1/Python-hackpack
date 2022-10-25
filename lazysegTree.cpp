#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long int ll;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

struct node {
    int lo, hi, mid;
	ll lazy;
    ll sum;
    node *left, *right;
    node(int l, int r, vi &values) {
        lo = l; hi = r;
        mid = (l + r) / 2;
		lazy = 0;
        if (l == r)
            sum = values[l];
        else {
            left = new node(l, mid, values);
            right = new node(mid + 1, r, values);
            sum = left->sum + right->sum;
        }
    }
    void update(int i, ll value) {
        if (lo == hi) {
            sum = value;
            return;
        }
        if (i <= mid) left->update(i, value);
        else right->update(i, value);
        sum = left->sum + right->sum;
    }

	void update(int l, int r, ll value) {
		if (l > hi || r < lo)
			return;
		if (l <= lo && hi <= r) {
			lazy += value;
			return;
		} 
		push();
		left->update(l, r, value);
		right->update(l, r, value);
	}

	void push() {
		sum += lazy * (hi - lo + 1);
		if (lo == hi) return void(lazy = 0);
		left->lazy += lazy;
		right->lazy += lazy;
		lazy = 0;
	}

    ll query(int l, int r) {
        if (l > hi || r < lo) 
            return 0;
		push();
        if (l <= lo && hi <= r) 
            return sum;
        return left->query(l, r) + right->query(l, r);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,q; cin >> n >> q;
	vi arr(n);
	node segtree(0, n - 1, arr);
	for (int i = 0; i < q; i++) {
		int qType; cin >> qType;
		if (qType == 1) {
			int t; cin >> t; t--;
			cout << segtree.query(t, t) << '\n';
		} else {
			int l, r, x; cin >> l >> r >> x;	
			l--; r--;
			segtree.update(l, r, x);
		}
	}
    return 0;
}