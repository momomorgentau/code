//ABC_201_D
//Game_in_Momotestu_World
//1317
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> A(h);
	rep(i, h) cin >> A[i];
	vector<vector<int>> dp(h + 5, vector<int>(w + 5));
	/*
	if ((h - 1 + w - 1) % 2 == 0)
	{
		if (A[h - 1][w - 1] == '+') dp[h - 1][w - 1] = -1;
		else dp[h - 1][w - 1] = 1;
	}
	else
	{
		if (A[h - 1][w - 1] == '+') dp[h - 1][w - 1] = 1;
		else dp[h - 1][w - 1] = -1;
	}
	*/
	
	const int INF = 1e9;
	for (int y = h - 1; y >= 0; --y)
	{
		for (int x = w - 1; x >= 0; --x)
		{
			if (x == w - 1 && y == h - 1) continue;
			
			bool Takahashi = false;
			if ((x + y) % 2 == 0) Takahashi = true;
			int dp1, dp2;
			if (x + 1 >= w)
			{
				dp1 = INF;
				if (Takahashi) dp1 *= -1;
			}
			else
			{
				if (Takahashi)
				{
					dp1 = dp[y][x + 1] + (A[y][x+1] == '+' ? 1 : -1);
				}
				else
				{
					dp1 = dp[y][x + 1] + (A[y][x+1] == '+' ? -1 : +1);
				}
			}

			if (y + 1 >= h)
			{
				dp2 = INF;
				if (Takahashi) dp2 *= -1;
			}
			else
			{
				if (Takahashi)
				{
					dp2 = dp[y+1][x] + (A[y+1][x] == '+' ? 1 : -1);
				}
				else
				{
					dp2 = dp[y+1][x] + (A[y+1][x] == '+' ? -1 : 1);

				}
			}
			
			if (Takahashi)
			{
				dp[y][x] = max(dp1, dp2);
			}
			else
			{
				dp[y][x] = min(dp1, dp2);
			}
		}

	}
	
	if (dp[0][0] > 0) cout << "Takahashi" << endl;
	else if (dp[0][0] < 0) cout << "Aoki" << endl;
	else cout << "Draw" << endl;
	return 0;
}