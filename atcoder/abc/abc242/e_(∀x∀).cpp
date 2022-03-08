//----------------------------
//ABC 242 E
//(ÅÕxÅÕ)
//1365
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int MOD = 998244353;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		vector<vector<ll>> dp(26, vector<ll>(2));

		dp[0][1] = 1;
		int rp = (n + 1) / 2;

		rep(i, rp)
		{
			int c = s[i] - 'A';
			vector<vector<ll>> tmp(26, vector<ll>(2));

			rep(j, 26)
			{
				rep(k, 26)
				{
					tmp[k][0] += dp[j][0];
					tmp[k][0] %= MOD;
				}
				//s[i]Åhà»â∫ÅhÇÃï∂éö
				rep(k, c)
				{
					tmp[k][0] += dp[j][1];
					tmp[k][0] %= MOD;
				}
				tmp[c][1] += dp[j][1];

			}
			swap(dp, tmp);
		}

		ll ans = 0;
		for (const auto& v : dp)
		{
			ans += v[0] + v[1];
			ans %= MOD;
		}


		rep(i, n / 2)
		{
			if (s[(n / 2) - 1 - i] > s[rp + i])
			{
				ans--;
				if (ans < 0) ans += MOD;
				break;
			}
			else if (s[(n / 2) - 1 - i] == s[rp + i])
			{
				continue;
			}
			else
			{
				break;
			}
		}


		printf("%d\n", ans);
	}

}