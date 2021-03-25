//ABC_118_B_Foods_Loved_by_Everyone
//148
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	rep(i,n)
	{
		int k; cin >> k;
		rep(j, k)
		{
			int a; cin >> a;
			++v[a-1];
		}
	}
	int ans = 0;
	for (auto vi : v) if (vi == n) ++ans;
	cout << ans << endl;

	return 0;
}