//----------------------------
//ABC 236 D
//Dance
//1190
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int n;
ll ans = 0;
vector<vector<ll>> a;

void dfs(vector<int> v, int used, bool odd)
{
	if (used == (1 << (2 * n)) - 1)
	{
		ll now = 0;
		for (int i = 0; i < n * 2; i += 2)
		{
			int a1 = v[i];
			int a2 = v[i + 1];
			if (a1 > a2)
			{
				swap(a1, a2);
			}
			now ^= a[a1][a2 - a1 - 1];
		}
		ans = max(ans, now);
		return;
	}

	if (odd)
	{
		rep(i, 2 * n)
		{
			if ((used >> i) & 1)
			{
				continue;
			}
			vector<int> t = v;
			t.emplace_back(i);
			int u = used | (1 << i);
			dfs(t, u, false);
		}
	}
	else
	{
		rep(i, 2 * n)
		{
			if ((used >> i) & 1)
			{
				continue;
			}
			else
			{
				v.emplace_back(i);
				used |= (1 << i);
				dfs(v, used, true);
				break;
			}
		}
	}


}
int main()
{
	cin >> n;
	a.resize(n * 2 - 1);
	rep(i, 2 * n - 1)
	{
		rep(j, 2 * n - 1 - i)
		{
			int ai;
			cin >> ai;
			a[i].emplace_back(ai);
		}
	}
	vector<int> emp(1, 0);

	dfs(emp, 1, true);
	cout << ans << endl;
	return 0;
}