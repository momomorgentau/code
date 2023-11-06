//----------------------------
// ABC 327 B 
// A^A
// 129
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll b;
	cin >> b;
	const ll MAX = 20;
	ll ans = -1;
	for(ll i = 1; i < MAX; i++)
	{
	    ll now = b;
		bool ok = true;
		rep(j,i)
		{
		    if(now % i == 0)
			{
			    now /= i;
			}
			else
			{
			    ok = false;
				break;
			}
		}
		if(ok && now == 1)
		{
		    ans = i;
			break;
		}
	}
	cout << ans << endl;
    return 0;
}

