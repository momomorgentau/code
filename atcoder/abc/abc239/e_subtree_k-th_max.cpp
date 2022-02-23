//----------------------------
//ABC_239_E
//Subtree K-th Max
//1084
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

vector<int> v;
vector<int> ans;
vector<vector<int>> g;
vector<priority_queue<P,vector<P>,greater<P>>> query;
vector<int> used;

vector<int> dfs(int a)
{
	priority_queue<int, vector<int>> pq;
	for (const auto& e : g[a])
	{
		if (used[e] == 1)
		{
			continue;
		}
		used[e] = 1;
		vector<int> v;
		v = dfs(e);
		for (const auto& l : v)
		{
			pq.emplace(l);
		}
	}
	pq.emplace(v[a]);
	int count = -1;
	vector<int> res;

	while (!pq.empty() && count <= 20)
	{
		++count;
		int p = pq.top();
		pq.pop();
		res.emplace_back(p);
		
		if (query[a].empty())
		{
			continue;
		}
		
		while (!query[a].empty())
		{
		    auto [ki, ii] = query[a].top();
		    if (ki != count)
		    {
				break;
		    }
			ans[ii] = p;
			query[a].pop();
		}
	}
	return res;
}




int main()
{
	int n, q;
	cin >> n >> q;
	v.resize(n);
	g.resize(n);
	query.resize(n);
	ans.resize(q);
	used.resize(n,-1);
	rep(i, n) cin >> v[i];
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	rep(i, q)
	{
		int v, k;
		cin >> v >> k;
		--v; --k;
		query[v].emplace(k,i);
	}
	used[0] = 1;
	dfs(0);
	for (const auto& a : ans)
	{
		printf("%d\n", a);
	}
	return 0;
}