//----------------------------
//ABC 260 F
//Find 4-cycle
//1995
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
	int s, t, m;
	cin >> s >> t >> m;
	vector<vector<int>> g(s);
	rep(i, m)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].emplace_back(v - s);
	}
	vector<vector<int>> table(t, vector<int>(t, -1));
	rep(i, s)
	{
		for (const auto& a : g[i])
		{
			for (const auto& b : g[i])
			{
				if (a == b) continue;
				if (table[a][b] == -1)
				{
					table[a][b] = i;
				}
				else
				{
					cout << i + 1 << " " << a + s + 1 << " " << table[a][b] + 1 << " " << b + s + 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}