//----------------------------
//ABC 260 D
//Draw Your Cards
//1074
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
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	rep(i, n) --p[i];


	map<int, P> mp;
	set<int> s;
	const int INF = 1e9 + 7;
	s.insert(INF);
	vector<int> ans(n, -1);
	rep(i, n)
	{
		int pi = p[i];
		if (k == 1)
		{
			ans[pi] = i + 1;
			continue;
		}
		int d = INF;
		if (s.size() >= 1)
		{
			auto it = s.upper_bound(pi);
			d = *it;

		}


		if (d == INF)
		{
			mp[pi] = make_pair(1, -1);
			s.insert(pi);
		}
		else
		{
			mp[pi].first = mp[d].first + 1;
			mp[pi].second = d;
			if (s.size() >= 1) s.erase(d);

			if (mp[pi].first >= k)
			{
				int idx = pi;
				while (idx >= 0)
				{
					ans[idx] = i + 1;
					idx = mp[idx].second;
				}
			}
			else
			{
				s.insert(pi);
			}
		}
	}
	rep(i, n) cout << ans[i] << endl;


	return 0;
}