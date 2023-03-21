class HLD
{
private:
	int n;
	vector<int> s;
	vector<vector<int>> g;
	vector<int> p;
	vector<int> q;
	vector<int> hld;
	vector<int> anc;
	vector<int> d;
	// 部分木の大きさを求める
	int size(int a)
	{
		if (s[a] != 0) return s[a];
		s[a] = 1;
		for (const auto& e : g[a])
		{
			if (p[a] == e) continue;
			s[a] += size(e);
		}
		return s[a];
	}
public:

	HLD(int _n)
	{
		n = _n;
		s.resize(n);
		g.resize(n);
		anc.resize(n);
		d.resize(n);
		p.resize(n);
		q.resize(n);
	}
	// HLDの順番を設定します
	void proc(int a, int b)
	{
		q[a] = hld.size();
		hld.emplace_back(a);
		anc[a] = b;

		// 葉に到達したら戻る
		int mx = 0;
		int x = -1;
		for (const auto& e : g[a])
		{
			if (p[a] == e) continue;
			if (size(e) > mx)
			{
				mx = size(e);
				x = e;
			}
		}
		if (x == -1) return;
		proc(x, b);
		for (const auto& e : g[a])
		{
			if (p[a] == e) continue;
			if (e == x) continue;
			proc(e, e);
		}
	}

	// 頂点の深さを設定します
	int depth(int a)
	{
		if (d[a] != 0)return d[a];
		if (p[a] == -1) return 0;
		return d[a] = 1 + depth(p[a]);
	}

	// 親番号を設定します
	void build()
	{
		queue<int> que;
		que.emplace(0);
		for (auto& e : p) e = -2;
		p[0] = -1;

		while (!que.empty())
		{
			int v = que.front();
			que.pop();
			for (const auto& e : g[v])
			{
				if (p[e] != -2) continue;
				p[e] = v;
				que.emplace(e);
			}
		}
	}

	// HLDクエリを取得します
	vector<pair<int, int>> query(int u, int v)
	{
		vector<pair<int, int>> res;
		while (anc[u] != anc[v])
		{
			if (depth(anc[u]) <= depth(anc[v]))
			{
				res.emplace_back(q[anc[v]], q[v]);
				v = p[anc[v]];
			}
			else
			{
				res.emplace_back(q[anc[u]], q[u]);
				u = p[anc[u]];
			}
		}
		res.emplace_back(make_pair(min(q[u], q[v]), max(q[u], q[v])));
		return res;
	}

	// 辺を追加します
	void add(int u, int v)
	{
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	int ancester(int a) { return anc[a]; } // 集合の中の一番浅い頂点
	int parent(int a) { return p[a]; } // 親
	int o2e(int a) { return hld[a]; } // HLDの番号->頂点のマッピング
	int e2o(int a) { return q[a]; } // 頂点->HLDの番号のマッピング
};