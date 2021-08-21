//ABC_210_E
//Ring MST
//1618
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<P> p(m);
	for (auto& [c, a] : p) cin >> a >> c;
	sort(p.begin(), p.end());
	ll ans = 0;
	for (auto [c, a] : p)
	{
		ll g = gcd(n, a);
		ans += (n - g) * c;
		n = g;
	}

	if (n != 1) ans = -1;
	cout << ans << endl;
}