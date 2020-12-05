//1393
//abc_153_f_silver_fox_vs_monster
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int n, d, a;
	cin >> n >> d >> a;
	vector<P> xh;
	rep(i, n)
	{
		int x, h;
		cin >> x >> h;
		xh.emplace_back(x, h);
	}
	sort(xh.begin(), xh.end());
	int d2 = d * 2;
	queue<pair<ll, ll>> q;
	ll sch = 0;
	ll ans = 0;
	rep(i, n)
	{
		int xi = xh[i].first;
		int hi = xh[i].second;
		while (!q.empty() && q.front().first < xi)
		{
			sch -= q.front().second;
			q.pop();
		}
		hi -= sch;
		if (hi > 0)
		{
			ll t = (hi + a - 1) / a;
			ans += t;
			ll add_sch = t * a;
			sch += add_sch;
			q.emplace(xi + d2, add_sch);
		}
	}

	cout << ans << endl;

	return 0;
}
