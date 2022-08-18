//Educational DP Contest C
//Vacation
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n; cin >> n;
	vector<ll> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	vector<ll> dp(3);
	rep(i, n)
	{
		vector<ll> tmp(3);
		tmp[0] = max(dp[1], dp[2]) + a[i];
		tmp[1] = max(dp[2], dp[0]) + b[i];
		tmp[2] = max(dp[0], dp[1]) + c[i];
		swap(dp, tmp);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}