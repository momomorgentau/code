//----------------------------
//ABC_233_C
//Product
//604
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

ll n;
ll x;

vector<vector<ll>> l;

ll ans = 0;
void dfs(ll s, int m, int pos)
{
	if (s % l[m][pos] != 0)
	{
		return;
	}

	s /= l[m][pos];

	if (m + 1 == n)
	{
		if (s == 1)
		{
			++ans;
		}
		return;
	}

	rep(j, l[m + 1].size())
	{
		dfs(s, m + 1, j);
	}
	return;
}

int main()
{
	cin >> n >> x;
	l.resize(n);
	rep(i, n)
	{
		int li; cin >> li;
		rep(j, li)
		{
			int lii; cin >> lii;
			l[i].emplace_back(lii);
		}
	}
	rep(i, l[0].size())
	{
		dfs(x, 0, i);
	}
	cout << ans << endl;
	return 0;
}
