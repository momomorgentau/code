//diff 89
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ll n;
	cin >> n;
	set<ll> s;
	for (ll i = 1; i * i <= n; ++i)
	{
		if (n % i != 0) continue;
		s.insert(i);
		s.insert(n / i);
	}

	auto it = s.begin();
	rep(i, s.size()) cout << *it++ << endl;

	return 0;
}