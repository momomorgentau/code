//----------------------------
// ABC 295 C
// Socks
// 122
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
	map<ll, ll>mp;
	rep(i, n)
	{
		int a;
		cin >> a;
		mp[a]++;
	}
	ll ans = 0;
	for (const auto& [ignore, v] : mp)
	{
		ans += v / 2;
	}
	cout << ans << endl;


	return 0;
}