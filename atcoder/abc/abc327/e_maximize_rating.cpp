//----------------------------
// ABC 327 E 
// 1227
// Maximize Rating
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) cin >> p[i];
	vector<double> dp(n+1);
	const double q = 0.9;
	rep(i,n)
	{
	    vector<double> tmp(n+1);
	    rep(j, i+1)
		{
		    tmp[j] = max(dp[j], tmp[j]);
			tmp[j+1] = max(dp[j] * q + p[i], tmp[j+1]); 
		}
		swap(tmp, dp);
	}
	double ans = -1e18;
	double z = 1;
	rep(i, n)
	{
	    ans = max(dp[i+1] / z - 1200 / sqrt(i+1), ans);
		z = z * q + 1; 
	}
	printf("%.7f\n", ans);
    return 0;
}

