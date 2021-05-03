//ABC_193_B_Play_Snuke
//37
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
	const int inf = (1e9 + 7);
	int ans = inf;
	rep(i, n)
	{
		int a, p, x;
		cin >> a >> p >> x;
		if (x - a > 0) ans = min(ans, p);
	}
	if (ans == inf)  ans = -1;
	cout << ans << endl;
	return 0;
}