//----------------------------
//ABC 263 B
//Ancestor
//136
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n; cin >> n;
	vector<int> p(n, 0);
	rep(i, n - 1) cin >> p[i + 1];
	rep(i, n) --p[i];
	int ans = 0;
	int q = n - 1;
	while (q > 0)
	{
		++ans;
		q = p[q];
	}
	cout << ans << endl;
	return 0;
}