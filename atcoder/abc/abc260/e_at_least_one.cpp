//----------------------------
//ABC 260 E
//At Least One
//1692
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
	vector<P> ab(n);
	rep(i, n) cin >> ab[i].first >> ab[i].second;
	rep(i, n) --ab[i].first;
	rep(i, n)--ab[i].second;

	sort(ab.begin(), ab.end());
	set<int> b;
	vector<int> imo(m + 10);
	int idx = 0;
	rep(i, m)
	{
		int p = -1;
		if (!b.empty()) p = *(--(b.end()));

		int q = ab[n - 1].first;
		int d = max(p, q);
		if (!b.empty() && *b.begin() < i) break;


		int l = d - i + 1;
		int r = m - i;
		imo[l]++;
		imo[r + 1]--;


		while (idx < n && ab[idx].first <= i)
		{
			b.insert(ab[idx].second);
			++idx;
		}

	}
	rep(i, m + 1) imo[i + 1] += imo[i];

	reps(i, 1, m + 1) cout << imo[i] << " ";
	return 0;
}