//----------------------------
// ABC 329 B 
// 20
// Next
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int mx = 0;
	rep(i,n) mx = max(a[i], mx);
	int ans = 0;
    rep(i,n)
	{
	    if(a[i] == mx) continue;
		ans = max(ans, a[i]);
	}
	cout << ans << endl;
    return 0;
}

