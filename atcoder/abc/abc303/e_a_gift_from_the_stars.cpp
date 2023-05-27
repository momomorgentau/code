//----------------------------
// ABC 303 E 
// A Gift From the Stars
// 1113
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
	cin >> n;
	vector<int> d(n);
	vector<set<int>> g(n);
	rep(i,n-1)
	{
	    int u,v;
		cin >> u >> v;
		u--;v--;
		d[u]++;
		d[v]++;
		g[u].insert(v);
		g[v].insert(u);
	}
	queue<int> q;
	rep(i,n)
	{
	    if(d[i] == 1) q.emplace(i);
	}
	vector<int> ans;
	while(!q.empty())
	{
	    int a = q.front();
		q.pop();
		if(g[a].size() == 0) continue;
		int p = *g[a].begin();
		for(const auto& e:g[p])
		{
			for(const auto&ee: g[e])
			{
			    if(ee == p) continue;
			    d[ee]--;
				g[ee].erase(e);
				if(d[ee] == 1) q.emplace(ee);
			}
			d[e] = 0;
			g[e].clear();
		}
		ans.emplace_back(g[p].size());
		g[p].clear();
		d[p] = 0;
	}
	sort(ans.begin(),ans.end());
	for(const auto&a:ans) printf("%d ",a);
	
    return 0;
}

