//ABC_193_C_Unexpressed
//379
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll n;
	cin >> n;
	map<ll, bool> mp;
	ll ans = n;
	for (ll i = 2; i * i <= n; ++i)
	{
		ll ni = i*i;
		while (ni <= n)
		{
			if (!mp[ni])
			{
				--ans;
				mp[ni] = true;
			}
			ni *= i;
		}
	}
	cout << ans << endl;
	return 0;
}