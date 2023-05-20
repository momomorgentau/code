//----------------------------
// ABC 302 D 
// Impartial Gift
// 682
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll n,m,d;
	cin >> n >> m >> d;
	vector<ll> a(n);
	vector<ll> b(m);
	rep(i,n) cin >> a[i];
	rep(i,m) cin >> b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	{
		int j = 0;
		bool ok = false;
		rep(i, n)
		{
			while(true)
			{
				if(j >= m) break;
				if(abs(a[i] - b[j]) <= d)
				{
					ok = true;
					break;
				}
				if(a[i] < b[j]) break;
				else j++;
			}
			if(ok) break;
		}
		if(!ok)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	const ll INF = 4e18;
	b.emplace_back(INF);
	b.emplace_back(-INF);
	b.emplace_back(-INF);
	sort(b.begin, b.end());

	ll ans = -1;
	ll now = 0;
	rep(i,n)
	{
		ll c = a[i] + d;
		ll it = lower_bound(b.begin(),b.end(),c);
		ll now0 = *it;
		ll now1 = *(--it);
		if(abs(a[i]-(now0)) <= d) ans = max(ans,a[i]+now0);
		if(abs(a[i]-(now1)) <= d) ans = max(ans,a[i]+now1);
	}
	cout << ans << endl;

	return 0;
}

