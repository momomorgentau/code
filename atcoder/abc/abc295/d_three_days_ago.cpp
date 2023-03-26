//----------------------------
// ABC 295 D
// Three Days Ago
// 939
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
	cin >> s;
	vector<ll> p(1 << 10);
	p[0] = 1;
	ll now = 0;
	for (const auto& c : s)
	{
		int d = c - '0';
		now = now ^ (1 << d);
		p[now]++;
	}
	ll ans = 0;
	for (const ll& q : p)
	{
		ans += q * (q - 1) / 2;
	}
	cout << ans << endl;

	return 0;
}