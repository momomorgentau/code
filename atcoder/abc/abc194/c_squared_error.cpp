//ABC194C_Squared_Error
//386
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> a1(n);
	rep(i, n) cin >> a1[i];
	vector<ll> a2(n);
	rep(i, n) a2[i] = a1[i] * a1[i];
	vector<ll> s1(n);
	vector<ll> s2(n);
	for (int i = n - 1; i >= 1; --i)
	{
		s1[i - 1] = s1[i] + a1[i];
		s2[i - 1] = s2[i] + a2[i];
	}
	ll ans = 0;
	rep(i, n)
	{
		ans += (n - 1 - i) * a2[i] - 2 * a1[i] * s1[i] + s2[i];
	}
	cout << ans << endl;


	return 0;
}