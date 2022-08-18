//Educational DP Contest F
//LCS
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	string s, t; cin >> s >> t;
	int sz = s.size();
	int tz = t.size();
	vector<vector<int>> dp(sz + 1, vector<int>(tz + 1, 0));
	rep(i, sz)rep(j, tz)
	{
		if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
		else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
	}
	int l = dp[sz][tz];
	string ans = "";
	int sidx = sz;
	int tidx = tz;
	s = 'X' + s;
	t = 'X' + t;
	while (l > 0)
	{
		if (s[sidx] == t[tidx])
		{
			ans += s[sidx];
			sidx--;
			tidx--;
			l--;
		}
		else if (sidx > 0 && dp[sidx][tidx] == dp[sidx - 1][tidx])
		{
			sidx--;
		}
		else
		{
			tidx--;
		}

	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}