//----------------------------
// ABC 302 E 
// Isolation
// 988
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{   
	int n,q;
	cin >> n >> q;
	vector<set<int>> g(n);
	vector<int> d(n);
	int ans = n;
	while(q--)
	{
		int t; cin >> t;
		if(t == 1)
		{
			int u,v;
			cin >> u >> v;
			--u,--v;
			if(d[u] == 0) --ans;
			if(d[v] == 0) --ans;
			d[u]++;
			d[v]++;
			g[u].insert(v);
			g[v].insert(u);
		}
		if(t == 2)
		{
			int v;
			cin >> v;
			v--;
			if(g[v].size() != 0)
			{			
				for(const auto& u:g[v])
				{
					d[u]--;
					if(d[u] == 0) ++ans;
					g[u].erase(v);
				}
				g[v].clear();
				d[v] = 0;
				++ans;
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}

