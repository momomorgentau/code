//251
//abc169_b_multiplication2

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

ll inf = 1e18;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] == 0) 
		{
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = 1;
	rep(i, n)
	{
		
		if (ans > inf / a[i])
		{
			cout << -1 << endl;
			return 0;
		}
		else ans *= a[i];
	}
	cout << ans << endl;
	return 0;
}


