//----------------------------
//ABC_237_E
//Skiing
//1208(after contest)
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
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	vector<vector<P>> g(n);
	rep(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		int cuv = h[u] - h[v];
		int cvu = -cuv;
		if (cuv >= 0)
		{
			cuv = 0;
			cvu *= -1;
		}
		else
		{
			cuv *= -1;
			cvu = 0;
		}
		g[u].emplace_back(make_pair(v, cuv));
		g[v].emplace_back(make_pair(u, cvu));
	}
	const int INF = 1e9;
	vector<int> d(n, INF);
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, 0);
	d[0] = 0;
	while (!pq.empty())
	{
		auto [c, a] = pq.top();
		pq.pop();
		for (const auto& [e, nc] : g[a])
		{
			if (d[e] <= d[a] + nc)
			{
				continue;
			}
			d[e] = d[a] + nc;
			pq.emplace(d[e], e);
		}
	}
	int ans = -INF;
	rep(i, n)
	{
		ans = max(ans, (h[0] - h[i]) - d[i]);
	}
	cout << ans << endl;
	return 0;
}