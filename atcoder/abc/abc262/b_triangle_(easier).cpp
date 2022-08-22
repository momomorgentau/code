//----------------------------
//ABC 262 B
//Triangle (Easier)	
//220
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
	vector<vector<int>> g(n, vector<int>(n, -1));
	rep(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	int ans = 0;
	rep(i, n)reps(j, i + 1, n)reps(k, j + 1, n)
	{
		if (g[i][j] != 1) continue;
		if (g[j][k] != 1) continue;
		if (g[k][i] != 1) continue;
		++ans;
	}
	cout << ans << endl;
	return 0;
}