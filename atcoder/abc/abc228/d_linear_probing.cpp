//----------------------------
//ABC_228_D
//Linear Probing
//1035
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
	const int MOD = 1048576;
	int q;
	cin >> q;
	set<int> s;
	rep(i, MOD)
	{
		s.insert(i);
	}
	s.insert(MOD);
	vector<ll> a(MOD, -1);
	while (q--)
	{
		int t; ll x;
		cin >> t >> x;
		if (t == 1)
		{
			int h = x % MOD;
			h = *s.lower_bound(h);
			if (h == MOD)
			{
				h = *s.begin();
			}
			a[h] = x;
			s.erase(h);
		}
		else
		{
			cout << a[x % MOD] << endl;
		}
	}

	return 0;
}