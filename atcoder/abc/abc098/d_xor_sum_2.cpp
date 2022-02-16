//----------------------------
//ABC_098_D
//Xor Sum 2
//1404
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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> s(n + 1), x(n + 1);
	rep(i, n)
	{
		s[i + 1] = s[i] + a[i];
		x[i + 1] = x[i] ^ a[i];
	}
	ll ans = 0;
	rep(i, n)
	{
		int l = i;
		int r = n+1;
		while (r - l > 1)
		{
			int wj = (l + r) / 2;
			ll si = s[wj] - s[i];
			ll xi = x[wj] ^ x[i];
			if (si > xi)
			{
				r = wj;
			}
			else
			{
				l = wj;
			}
		}
		ans += (l - i);
	}
	cout << ans << endl;

}