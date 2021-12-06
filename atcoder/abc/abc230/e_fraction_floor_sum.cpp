//----------------------------
//ABC_230_E
//Fracyion_Floor_Sum
//969
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	ll n; cin >> n;
	ll ans = 0;
	ll i = 1;
	while (i <= n)
	{
		ll tmp = n / i;
		ll ac = n + 1;
		ll wa = 1;
		while (ac - wa > 1)
		{
			ll wj = (ac + wa) / 2;
			if (n / wj < tmp) ac = wj;
			else wa = wj;
		}
		ans += tmp * (ac - i);
		i = ac;

	}
	cout << ans << endl;

	return 0;
}