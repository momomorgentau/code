//diff 721
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ll x, y;
	int a, b;
	cin >> x >> y >> a >> b;
	ll ans = 0;
	while (1)
	{
		if (x >= y / a) break;
		if (x * a >= x + b) break;
		++ans;
		x *= a;
	}
	ans += (y - 1 - x) / b;
	cout << ans << endl;
	return 0;
}
