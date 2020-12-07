//172
//abc149_c_next_prime
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int x;
	cin >> x;
	ll ans = x - 1;
	while (1)
	{
		++ans;
		bool ok = true;
		for (ll i = 2; i * i <= x; i++)
		{
			if (ans % i == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok) break;
	}
	cout << ans << endl;
	return 0;
}