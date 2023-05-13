//----------------------------
// ABC 301 D 
// Bitmask
// 
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string s;
	ll n;
	cin >> s >> n;
	ll now = 0;
    int sz = s.size();
	for(ll i = 0; i < s.size(); i++)
	{
	    if(s[i] != '1') continue;
		now += (1LL << (sz-i-1));
	}
	if(now > n)
	{
	    cout << -1 << endl;
		return 0;
	}
	for(ll i = 0; i < s.size(); i++)
	{
	    if(s[i] != '?') continue;
		if(now + (1LL<<(sz-i-1)) <= n) now += (1LL<<(sz-i-1));
	}
	cout << now << endl;
    return 0;
}

