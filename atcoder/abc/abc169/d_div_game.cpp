//686
//abc169_d_div_game

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;
	multiset<ll> ms;
	ll tn = n;
	ll m = 2;
	for(ll m = 2; m*m <= n && tn > 1; ++m)
	{
		if (tn % m == 0)
		{
			while (1)
			{
				ms.insert(m);
				tn /= m;
				if (tn % m != 0) break;
			}
		}
	}

	if (tn != 1) ms.insert(n);

	int ans = 0;
	while (!ms.empty())
	{
		ll tp = *ms.begin();
		int np = ms.count(tp);
		ms.erase(tp);
		int c = 1;
		while (1) 
		{
			if (np >= c) ++ans, np -= c, ++c;
			else break;
		}
	}
	cout <<ans << endl;
	return 0;
}


