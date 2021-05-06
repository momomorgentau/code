#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n, m;
	cin >> n;
	vector<vector<int>> A(n, vector<int>(n));
	rep(i, n)rep(j, n)cin >> A[i][j];
	cin >> m;
	vector<int> B1(m), B2(m);
	rep(i, m) cin >> B1[i] >> B2[i];
	rep(i, m) --B1[i];
	rep(i, m) --B2[i];

	vector<int> prm;
	rep(i, n) prm.emplace_back(i);
	const int INF = 1e9;
	int ans = INF;
	do
	{
		//•s’‡‚ÌŒŸØ
		bool ok = true;
		rep(i, n - 1)
		{
			rep(j, m)
			{
				if (prm[i] == B1[j] && prm[i + 1] == B2[j]) ok = false;
				if (prm[i] == B2[j] && prm[i + 1] == B1[j]) ok = false;
			}
		}
		if (!ok) continue;
		int now = 0;
		rep(i, n) now += (A[prm[i]][i]);
		ans = min(ans, now);
	} while (next_permutation(prm.begin(), prm.end()));

	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}