#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
	ll n;
	int x, m;
	cin >> n >> x >> m;

	vector<int> rem(m, -1);

	ll ans = 0;
	ll a = x;
	int it = 0;
	rep(i, n) {
		if (rem[a] != -1) break;
		rem[a] = it;
		ans += a;
		a = (a * a) % m;
		++it;
	}

	if (it == n) {
		cout << ans << endl;
		return 0;
	}

	int its = rem[a];
	int l = it - its;
	vector<ll> sum(l + 1);
	sum[0] = 0;
	rep(i, l) {
		sum[i + 1] = sum[i] + a;
		a = (a * a) % m;
	}

	ll r = n - it;
	ans += (sum[l] * (r / l));
	int r2 = r % l;
	ans += sum[r2];
	cout << ans << endl;

	return 0;
}