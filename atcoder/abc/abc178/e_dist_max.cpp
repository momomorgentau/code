#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
const int inf = 2e9;
int main() {
	int n;
	cin >> n;
	int umax = -inf, umin = inf;
	int vmax = -inf, vmin = inf;

	rep(i, n) {
		int x, y;
		cin >> x >> y;
		int u = x - y;
		int v = x + y;
		umax = max(umax, u);
		umin = min(umin, u);
		vmax = max(vmax, v);
		vmin = min(vmin, v);
	}

	int ans = max(umax - umin, vmax - vmin);
	cout << ans << endl;
	return 0;
}