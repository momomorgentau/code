//ABC_192_D_Base_n
//1425
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll n2d(ll n,string x)
{
	ll res = 0;
	for(auto c: x)
	{
		if (res  > 2e18 / n)  return 2e18;
		else res = n * res + (c - '0');
	}
	return res;
}

int main()
{
	string x;
	ll m;
	cin >> x >> m;
	//コーナーケース
	if (x.size() == 1)
	{
		if (x[0] - '0' <= m) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	//最大値
	int md = 0;
	for (auto c : x) md = max(md,c-'0');

	ll ac = md;
	ll wa = 2e18;
	while (wa - ac > 1)
	{
		ll wj = (wa + ac) / 2;
		ll v = n2d(wj, x);
		if (v <= m) ac = wj;
		else wa = wj;
	}
	ll ans = ac - md;
	cout << ans << endl;
	return 0;
}