//----------------------------
//ABC 240 F
//Max Max Sum
//1589
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll a0 = 0;
		ll b0 = 0;
		ll ans = -1e18;

		rep(i, n)
		{
			ll x, y;
			cin >> x >> y;
			auto v = [a0, b0, x](ll s)
			{
				return a0 + s * b0 + s * (1 + s) * x / 2;
			};
			ans = max({ ans,v(1LL),v(y) });

			if (x != 0)
			{
				vector<ll> ss;
				ss.emplace_back((-2 * b0 + x) / (2 * x));
				ss.emplace_back(ss[0] + 1);
				ss.emplace_back(ss[0] - 1);


				for (const auto& si : ss)
				{
					if (1 <= si && si <= y)
					{
						ans = max(ans, v(si));
					}
				}
			}

			a0 = v(y);
			b0 += y * x;
		}
		cout << ans << endl;
	}
	return 0;
}