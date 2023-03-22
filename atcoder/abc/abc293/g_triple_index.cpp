//----------------------------
// ABC 293 G
// Triple Index
// 1753
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;


template<class T>
class MosAlgorithm
{
private:
	int n;
	vector<pair<T, T>> v;
public:
	MosAlgorithm(int _n)
	{
		n = _n;
	}

	void add(T l, T r)
	{
		v.emplace_back(l, r);
	}

	vector<T> get()
	{
		int sz = max(1, (int)std::sqrt(v.size()));
		vector<T> idxes((int)v.size());
		iota(idxes.begin(), idxes.end(), 0);
		std::sort(idxes.begin(), idxes.end(), [&](int a, int b)
			{
				T l0 = v[a].first;
				T l1 = v[b].first;
				T r0 = v[a].second;
				T r1 = v[b].second;
				if (l0 / sz != l1 / sz) return l0 < l1;
				else return r0 < r1;
			});
		return idxes;
	}


};
const int N = 2e5 + 10;

int main()
{
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i]--;
	vector<ll> ncm(n + 1);
	rep(i, n + 1)
	{
		ll p = i;
		ncm[i] = p * (p - 1) * (p - 2);
		ncm[i] /= 6LL;
	}
	vector<int> L(q), R(q);
	MosAlgorithm<ll> mo(n);
	rep(i, q)
	{
		cin >> L[i] >> R[i];
		--L[i];
		mo.add(L[i], R[i]);
	}
	auto ord = mo.get();

	vector<int> d(N);
	ll now = 0;
	int cl = 0;
	int cr = 0;

	vector<ll> ans(q);
	auto add = [&](int x)
	{
		now -= ncm[d[x]];
		now += ncm[++d[x]];
	};
	auto del = [&](int x)
	{
		now -= ncm[d[x]];
		now += ncm[--d[x]];
	};

	for (const auto& idx : ord)
	{
		int l = L[idx];
		int r = R[idx];
		while (r < cr) del(a[--cr]);
		while (cr < r) add(a[cr++]);
		while (l < cl) add(a[--cl]);
		while (cl < l) del(a[cl++]);

		ans[idx] = now;
	}
	for (const auto& a : ans) printf("%lld\n", a);
	return 0;
}
