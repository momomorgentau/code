//----------------------------
// ABC 294 G
// Distance Queries on a Tree
// 1702
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

template<class T>
class HLD
{
private:
	int n;
	vector<int> s;
	vector<vector<int>> g;
	vector<int> p;
	vector<int> q;
	vector<int> hld;
	vector<int> hldmp;
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
	int depth(int a)
	{
		if (d[a] != 0)return d[a];
		if (p[a] == -1) return 0;
		return d[a] = 1 + depth(p[a]);
	}

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

template<class T, T(*op)(T, T), T(*e)()>
class segtree
{
private:
	int n;
	vector<T> v;
public:
	segtree(int n_)
	{
		int x = 1;
		while (n_ > x) x <<= 1;
		n = x;
		v.resize(2 * n - 1, e());
	}
	void set(int k, T x)
	{
		k += n - 1;
		v[k] = x;
		while (k > 0)
		{
			k = (k - 1) / 2;
			v[k] = op(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	T get(int k) { return v[k + n - 1]; }
	//[a,b)
	T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
	T query_sub(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) return e();
		if (a <= l && r <= b) return v[k];
		T c1 = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
		T c2 = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
		return op(c1, c2);
	}

	//display segtree value
	void display(string text = "segtree value")
	{
		cout << text << endl;
		int cnt = 0;
		int end = 1 << cnt;
		int l = v.size();
		for (int i = 0; i < l; ++i)
		{
			cout << v[i] << " ";
			if (i == end - 1)
			{
				++cnt;
				end += 1 << cnt;
				cout << endl;
			}
		}
		cout << endl;
	}
};

ll e() { return 0; }
ll op(ll a, ll b) { return a + b; }

int main()
{
	int n;
	cin >> n;
	vector<tuple<int, int, ll>> E;
	HLD<int> hld(n);
	rep(i, n - 1)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		hld.add(u, v);
		E.emplace_back(u, v, w);
	}

	hld.build();
	hld.proc(0, 0);
	segtree<ll, op, e> sg(n);
	for (const auto& [u, v, w] : E)
	{
		if (hld.depth(u) < hld.depth(v)) sg.set(hld.e2o(v), w);
		else sg.set(hld.e2o(u), w);
	}
	int q; cin >> q;
	while (q--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
		{
			--x;
			auto [u, v, w] = E[x];
			if (hld.depth(u) < hld.depth(v)) sg.set(hld.e2o(v), y);
			else sg.set(hld.e2o(u), y);
		}
		else
		{
			int u = --x;
			int v = --y;
			auto query = hld.query(u, v);
			ll ans = 0;
			for (const auto& [l, r] : query)
			{
				ans += sg.query(l, r + 1);
			}
			int z = query[query.size() - 1].first;
			// 最後の頂点からの遷移分を余分に加算してるので引きます
			ans -= sg.query(z, z + 1);
			printf("%lld\n", ans);
		}
	}

	return 0;
}

