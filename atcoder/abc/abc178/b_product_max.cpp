#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main()
{
	vector<ll> a(4);
	rep(i, 4) cin >> a[i];

	vector<ll> pro;
	rep(i, 2)rep(j, 2) pro.emplace_back(a[i] * a[j + 2]);

	ll ans = LLONG_MIN;
	rep(i, 4) ans = max(ans, pro[i]);
	cout << ans << endl;
}