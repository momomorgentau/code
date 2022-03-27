//----------------------------
//ABC 245 C
//Choose Elements
//403
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	
	vector<int> dp(2);
	dp[0] = 1;
	dp[1] = 1;
	rep(i, n-1)
	{
		vector<int> t(2);

		if (dp[0] == 1)
		{
			t[0] |= (abs(a[i] - a[i + 1]) <= k);
			t[1] |= (abs(a[i] - b[i + 1]) <= k);
		}
		if (dp[1] == 1)
		{
			t[0] |= (abs(b[i] - a[i + 1]) <= k);
			t[1] |= (abs(b[i] - b[i + 1]) <= k);
		}
		swap(dp, t);

	}
	if (dp[0] == 1 || dp[1] == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
