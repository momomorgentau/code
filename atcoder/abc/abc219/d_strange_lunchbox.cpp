//----------------------------
//ABC_219_D
//Strange_Lunchbox
//1085
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
	int n, x, y;
	cin >> n >> x >> y;
	const int INF = 1e9;
	vector<vector<int>> dp(x + 5, vector<int>(y + 5, INF));
	dp[0][0] = 0;
	rep(i, n)
	{
		int a, b;
		cin >> a >> b;
		for (int j = x; j >= 0; --j)
		{
			for (int k = y; k >= 0; --k)
			{
				int nx = min(j + a, x);
				int ny = min(k + b, y);

				dp[nx][ny] = min(dp[nx][ny], dp[j][k] + 1);
			}
		}
	}
	if (dp[x][y] == INF) dp[x][y] = -1;
	cout << dp[x][y] << endl;
	return 0;
}