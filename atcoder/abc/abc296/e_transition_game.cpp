//----------------------------
// ABC 296 E
// Transition Game
// 1285
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

template<class T>
class SCC
{
public:
	SCC(T n_)
	{
		n = n_;
		g.resize(n);
		rg.resize(n);
		used.resize(n);
		belong.resize(n);
	}

	void AddEdge(T u, T v)
	{
		g[u].emplace_back(v);
		rg[v].emplace_back(u);
	}

	void SCCBuild()
	{
		//‰Šú‰»ˆ—
		for (auto& used_i : used) used_i = 0;
		prm.clear();
		scc_graph = vector<vector<T>>();
		belong = vector<T>(n);
		k = -1;

		//’Tõ‡‚ğì¬
		for (int i = 0; i < n; ++i)
		{
			if (used[i] == 1) continue;
			used[i] = 1;
			dfs1(i);
		}
		reverse(prm.begin(), prm.end());

		//¬•ª‚²‚Æ‚É•ª‰ğ
		for (auto& used_i : used) used_i = 0;
		for (const auto& a : prm)
		{
			if (used[a] == 1) continue;
			used[a] = 1;
			++k;
			scc_graph.emplace_back(vector<T>());
			dfs2(a);

			//Š‘®‚ğƒƒ‚‚·‚éB
			for (const auto& e : scc_graph[k])
			{
				belong[e] = k;
			}

		}
	}

	vector<vector<T>> GetSCCGraph()
	{
		return scc_graph;
	}

	T GetSCCSize()
	{
		return k + 1;
	}

	vector<T> GetBelong()
	{
		return belong;
	}


private:
	vector<vector<T>> g;
	vector<vector<T>> rg;

	vector<T> used;
	vector<T> prm;
	vector<vector<T>> scc_graph;
	T k = -1;
	T n = -1;

	vector<T> belong;

	void dfs1(T a)
	{
		for (const auto& e : g[a])
		{
			if (used[e] == 1) continue;
			used[e] = 1;
			dfs1(e);
		}
		prm.emplace_back(a);
	}

	void dfs2(T a)
	{
		//ƒOƒ‰ƒt‚Ìs‚«‚ª‚¯‚É—v‘f‚ğ‹L˜^
		//\’z‚·‚éDAG‚Ì‡”Ô‚É‚È‚é‚Í‚¸B
		scc_graph[k].emplace_back(a);
		for (const auto& e : rg[a])
		{
			if (used[e] == 1) continue;
			used[e] = 1;
			dfs2(e);
		}
	}

};

int main()
{
	int n;
	cin >> n;
	SCC<int> scc(2 * n);
	vector<int> g(n);
	rep(i, n)
	{
		int a;
		cin >> a;
		--a;
		g[i] = a;

		if (i == a)
		{
			scc.AddEdge(a, a + n);
			scc.AddEdge(a + n, a);
		}
		else
		{
			scc.AddEdge(i, a);
		}
	}
	scc.SCCBuild();
	auto G = scc.GetSCCGraph();
	auto belong = scc.GetBelong();
	int k = 0;
	vector<int> used(n, 0);
	while (1)
	{
		if (k >= scc.GetSCCSize())
		{
			break;
		}
		int a = G[k][0];
		if (a >= n) a -= n;
		if (used[a] != 0)
		{
			k++;
			continue;
		}
		if (G[belong[a]].size() > 1)
		{
			used[a] = 1;
		}
		else
		{
			used[a] = -1;
		}
		queue<int> q;
		q.emplace(a);
		while (!q.empty())
		{
			int e = q.front();
			q.pop();
			int nx = g[e];
			if (used[nx] != 0) continue;
			int tk = belong[nx];
			//k = max(k, tk);
			if (G[tk].size() > 1 || used[e] == 1)
			{
				used[nx] = 1;
			}
			else used[nx] = -1;
			q.emplace(nx);
		}
		k++;

	}
	int ans = 0;
	for (const auto& e : used) ans += (e == 1);
	cout << ans << endl;


	return 0;
}

/*
–³‘Ê‚ÈŒvZ‚ğ‚µ‚Ä‚¢‚Ü‚·
§–ñ‚©‚çã—¬‚Ì•Â˜H‚©‚ç‘JˆÚ‚µ‚Ä‚­‚é‚±‚Æ‚Í‚È‚¢‚½‚ß
•Â˜H‚Ì”»’è‚Ì‚İ‚ğs‚¦‚Î‚æ‚¢‚Å‚·
*/