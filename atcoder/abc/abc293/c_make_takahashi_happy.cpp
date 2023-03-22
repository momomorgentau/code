//----------------------------
// ABC 293 C
// Make Takahashi Happy
// 431
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int H = 10;
int W = 10;
vector<vector<ll>> A(H, vector<ll>(W));
ll h, w;

ll dfs(int a, int b, vector<ll> g)
{
	ll res = 0;
	if (a == h - 1 && b == w - 1)
	{
		return 1;
	}
	if (a < h - 1)
	{
		bool ok = true;
		for (const auto& e : g)
		{
			if (A[a + 1][b] == e)
			{
				ok = false;
				break;
			}

		}
		if (ok)
		{
			vector<ll> tmp = g;
			tmp.emplace_back(A[a + 1][b]);
			res += dfs(a + 1, b, tmp);
		}
	}
	if (b < w - 1)
	{
		bool ok = true;
		for (const auto& e : g)
		{
			if (A[a][b + 1] == e)
			{
				ok = false;
				break;
			}

		}
		if (ok)
		{
			vector<ll> tmp = g;
			tmp.emplace_back(A[a][b + 1]);
			res += dfs(a, b + 1, tmp);
		}
	}
	return res;
}

int main()
{
	cin >> h >> w;
	rep(i, h)rep(j, w) cin >> A[i][j];
	vector<ll> f;
	f.emplace_back(A[0][0]);
	cout << dfs(0, 0, f) << endl;
	return 0;
}