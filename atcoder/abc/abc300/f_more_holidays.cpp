//----------------------------
// ABC 300 F
// More Holidays
// 1846
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll judge(ll idx, ll n, const vector<ll> &q)
{
    ll now = (idx/n) * q[n];
    return now + q[idx%n];
}

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<ll> q(n+1);
    rep(i,n) q[i+1] = q[i] + (s[i]=='x');
    ll ans = 0;
    reps(i, 1, n+1)
    {
	ll f0 = judge(i-1,n,q);
	ll l = i;
	ll r = n * m;
	while(l<=r)
	{
	    ll wj = (l+r)>>1;
	    ll f1 = judge(wj, n, q);
	    if(f1-f0<=k)l = wj+1;
	    else r = wj -1;
	}
	ans = max(ans,r-i+1);
    }
    cout << ans << endl;
    return 0;
}
