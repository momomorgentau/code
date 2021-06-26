//035
//Preserve_Connectivity
//*7
//task1
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int N = 5000;
vector<vector<int>> g;
stack<int> st;
vector<int> d(N + 5, -1);
vector<int> t(N + 5, 0);
void dfs(int a)
{
	for (auto e : g[a])
	{
		if (d[e] != -1) continue;
		st.emplace(e);
		d[e] = 1;
		dfs(e);
	}
	if (!t[st.top()])st.pop();
}


int main()
{
	int n, q;
	cin >> n;
	g.resize(n);
	rep(i, n - 1)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	cin >> q;
	while (q--)
	{
		int k; cin >> k;
		rep(i, n) d[i] = -1;
		rep(i, n) t[i] = 0;

		int s = -1;
		rep(i, k)
		{
			int ki; cin >> ki;
			--ki;
			t[ki] = 1;
			s = ki;
		}
		d[s] = 1;
		while (!st.empty()) st.pop();
		dfs(s);
		printf("%d\n", st.size());
	}


	return 0;
}