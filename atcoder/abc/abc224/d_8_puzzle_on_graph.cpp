//----------------------------
//ABC_224_D
//8_puzzle_on_graph
//1376
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int N = 9;

int main()
{
	int m;
	cin >> m;
	vector<vector<int>> nodes(N);
	rep(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}
	//初期状態の生成
	string init = "888888888";
	rep(i, N - 1)
	{
		int c; cin >> c;
		--c;
		init[c] = i + '0';
	}
	//9!の頂点のグラフを構成
	map<string, vector<string>> g;
	vector<int> s = { 0,1,2,3,4,5,6,7,8 };
	do
	{
		string ts = "";
		int idx = -1;
		for (const auto& a : s)
		{
			ts += a + '0';
			if (a == N - 1)
			{
				idx = ts.size() - 1;
			}
		}
		for (const auto& e : nodes[idx])
		{
			string nx = ts;
			swap(nx[idx], nx[e]);
			g[ts].emplace_back(nx);
		}
	} while (next_permutation(s.begin(), s.end()));

	//BFSで経路探索
	map<string, int> d;
	queue<string> q;
	q.emplace(init);
	d[init] = 0;
	while (!q.empty())
	{
		string a = q.front();
		q.pop();
		for (const auto& e : g[a])
		{
			if (d.count(e)) continue;
			d[e] = d[a] + 1;
			q.emplace(e);
		}
	}
	if (!d.count("012345678")) cout << -1 << endl;
	else cout << d["012345678"] << endl;
	return 0;
}