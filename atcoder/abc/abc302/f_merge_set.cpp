//----------------------------
// ABC 302 F 
// Merge Set
// 1430
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n,m;cin >> n >> m;
	vector<vector<int>> g(n+m);
	rep(i,n)
	{
		int a;cin >> a;
		rep(j,a)
		{
			int s; cin >> s;
			s--;
			g[s].emplace_back(i+m);
			g[i+m].emplace_back(s);
		}
	}
	const int INF = 1e9;
	queue<int> q;
	vector<int> d(n+m, INF);
	d[0] = 0;
	q.emplace(0);
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		for(const auto& e:g[a])
		{
			if(d[e] != INF) continue;
			d[e] = d[a] + 1;
			q.emplace(e);
		}
	}
	int ans = d[m-1];
	if(ans == INF) ans = 0;
	ans = ans / 2 - 1;
	cout << ans << endl;
	return 0;
}

