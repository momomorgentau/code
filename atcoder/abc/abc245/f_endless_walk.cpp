//----------------------------
//ABC 245 F
//Endless Walk
//1451
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


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
		//初期化処理
		for (auto& used_i : used) used_i = 0;
		prm.clear();
		scc_graph = vector<vector<T>>();
		belong = vector<T>(n);
		k = -1;
		
		//探索順を作成
		for (int i = 0; i < n; ++i)
		{
			if (used[i] == 1) continue;
			used[i] = 1;
			dfs1(i);
		}
		reverse(prm.begin(), prm.end());
		
		//成分ごとに分解
		for (auto& used_i : used) used_i = 0;
		for (const auto& a : prm)
		{
			if (used[a] == 1) continue;
			used[a] = 1;
			++k;
			scc_graph.emplace_back(vector<T>());
			dfs2(a);

			//所属をメモする。
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
		return k+1;
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
		//グラフの行きがけに要素を記録
		//構築するDAGの順番になるはず。
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
	int n, m;
	cin >> n >> m;
	SCC<int> scc(n);
	vector<vector<int>> g(n);
	rep(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].emplace_back(v);
		scc.AddEdge(u, v);
	}
	scc.SCCBuild();
	vector<vector<int>> scc_graph = scc.GetSCCGraph();
	vector<int> belong = scc.GetBelong();
	int size = scc.GetSCCSize();

	vector<int> dp(size, 0);
	int ans = 0;
	//トポロジカルソート、kが大きいほど末尾にある
	for (int i = size - 1; i >= 0; --i)
	{
		if (scc_graph[i].size() >= 2)
		{
			dp[i] = 1;
		}
		//2以上じゃなかったから遷移先がループを持つか
		else
		{
			for (const auto& e : g[scc_graph[i][0]])
			{
				dp[i] |= dp[belong[e]];
			}
		}

		if (dp[i]) ans += scc_graph[i].size();
	}
	cout << ans << endl;
	return 0;
}

