//1015
//abc_153_e_crested_lbis_vs_monster
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

const int inf = 1e9;
int main()
{
	int h, n;
	cin >> h >> n;

	vector<int> a(n);
	vector<int> b(n);

	rep(i, n) cin >> a[i] >> b[i];

	vector<int> dp(h + 1, inf);
	dp[0] = 0;

	rep(i, h)
	{
		rep(j, n)
		{
			int ai = a[j];
			int bi = b[j];
			int nidx = i + ai;
			nidx = min(nidx, h);

			if (dp[nidx] > dp[i] + bi)
			{
				dp[nidx] = dp[i] + bi;
			}

		}
	}
	cout << dp[h] << endl;

	return 0;
}
