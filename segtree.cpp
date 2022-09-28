#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long int ll;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

struct node {
    int lo, hi, mid;
    ll sum;
    node *left, *right;
    node(int l, int r, vi &values) {
        lo = l; hi = r;
        mid = (l + r) / 2;
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
    ll query(int l, int r) {
        if (l > hi || r < lo) 
            return 0;
        if (l <= lo && hi <= r) 
            return sum;
        return left->query(l, r) + right->query(l, r);
    }
};



void solve() {
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--)
        solve();
    return 0;
}
