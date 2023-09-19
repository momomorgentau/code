//----------------------------
// ABC 320 E 
// Somen Nagashi
// 1096
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
	vector<ll> ans(n);
	priority_queue<ll, vector<ll>, greater<ll>> pq0;
	priority_queue<P, vector<P>, greater<P>> pq1;
	rep(i,n) pq0.emplace(i);
	rep(i,m)
	{
	    ll t,w,s;
		cin >> t >> w >> s;
		while(!pq1.empty())
		{
		    auto[ts, idx] = pq1.top();
			if(ts > t) break;
			pq1.pop();
			pq0.emplace(idx);
		}

		if(pq0.empty())continue;

		ll idx = pq0.top();
		pq0.pop();
		ans[idx] += w;
		pq1.emplace(make_pair(t+s, idx));

	}
	for(const auto&a:ans)
	{
	    printf("%lld\n", a);
	}
    return 0;
}

