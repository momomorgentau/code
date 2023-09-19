//----------------------------
// ABC 320 D
// Relative Position
// 873
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n,m;
	cin >> n >> m;
	ll INF = 1e18;
	vector<ll> x(n, INF), y(n, INF);
	vector<P> xy(m);
	vector<vector<tuple<ll,ll,ll>>> g(n);
	rep(i,m)
	{
	    ll a, b , xi , yi;
	    cin >> a >> b >> xi >> yi;
		--a,--b;
		g[a].emplace_back(make_tuple(b,xi,yi));
		g[b].emplace_back(make_tuple(a,-xi,-yi));
	}
	queue<int> q;
	q.emplace(0);
	x[0] = 0;
	y[0] = 0;
	while(!q.empty())
	{
	    int a = q.front();
		q.pop();
		for(const auto&[b,xi,yi]:g[a])
		{
		    if(x[b] != INF || y[b] != INF) continue;
			x[b] = x[a] + xi;
			y[b] = y[a] + yi;
			q.emplace(b);
		}
	}
	rep(i,n)
	{
	    if(x[i] == INF || y[i] == INF)
		{
		    cout << "undecidable" << endl;
		}
		else
		{
		    cout << x[i] << " " << y[i] << endl;
		}
	}
    return 0;
}

