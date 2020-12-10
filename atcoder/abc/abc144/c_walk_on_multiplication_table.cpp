//320
//abc144_c_walk_on_multiplication_table
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	ll n;
	cin >> n;
	ll ans = 1e18;
	for (ll i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			ans = min(ans, i + n / i);
		}
	}
	ans -= 2;
	cout << ans << endl;
	return 0;
}