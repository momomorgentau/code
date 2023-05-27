//----------------------------
// ABC 303 D
// Shift vs. CapsLock
// 778
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll x,y,z;
	cin >> x >> y >> z;
	ll on = z;
	ll off = 0;
	string s; cin >> s;
    const ll INF = 1e18;
	for(const auto &c:s)
	{
	    ll con = INF;
		ll coff = INF;
	    if(c == 'a')
		{
		    con = min(on + min(y, z+z+x), con);
			con = min(off + min(x,y) + z, con);
			coff = min(on + z + min(x,y), coff);
			coff = min(off + min(x,z+z+y), coff);
		}
		else
		{
		    con = min(on + min(x,z+z+y), con);
			con = min(off + z + min(x,y), con);
			coff = min(on + min(x,y) + z, coff);
			coff = min(off + min(y,x+z+z), coff);
		}
		swap(on,con);
		swap(off,coff);
	}
	cout << min(on,off) << endl;

    return 0;
}

