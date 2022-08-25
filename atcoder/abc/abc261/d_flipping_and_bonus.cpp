//----------------------------
//ABC 261 D
//Flipping and Bonus
//801
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
	int n, m;
	cin >> n >> m;
	vector<ll> x(n);
	rep(i, n)cin >> x[i];
	vector<int> cy(n + 10, 0);
	rep(i, m)
	{
		ll c, y; cin >> c >> y;
		cy[c] = y;
	}
	vector<ll> dp(n + 10);
	rep(i, n)
	{
		vector<ll> tmp(n + 10);
		rep(j, i + 1)
		{
			tmp[j + 1] = max(dp[j] + x[i] + cy[j + 1], tmp[j + 1]);
			tmp[0] = max(dp[j], tmp[0]);
		}
		swap(dp, tmp);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}