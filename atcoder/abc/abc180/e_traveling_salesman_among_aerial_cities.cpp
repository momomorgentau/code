//diff 1226
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int inf = 1e+9 + 10;


int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> z(n);

	rep(i, n) cin >> x[i] >> y[i] >> z[i];

	vector<vector<int>> dp(n, vector<int>(1 << n, inf));
	dp[0][1] = 0;
	rep(s, 1 << n)//訪れた場所
	{
		rep(i, n) //今いる場所
		{
			for (int j = 1; j < n; ++j)//次に行く場所(0には戻らない)
			{
				int sj = 1 << j;
				if (s & sj || j == 0) continue;
				int c = abs(x[i] - x[j]);
				c += abs(y[i] - y[j]);
				c += max(0, z[j] - z[i]);

				dp[j][s + sj] = min(dp[i][s] + c, dp[j][s + sj]);
			}
		}
	}
	int ans = inf;
	//0に戻るまでのコストを計算
	for (int i = 1; i < n; ++i)
	{
		int c = abs(x[i] - x[0]);
		c += abs(y[i] - y[0]);
		c += max(0, z[0] - z[i]);

		ans = min(ans, dp[i][(1 << n) - 1] + c);
	}

	cout << ans << endl;

	return 0;
}
