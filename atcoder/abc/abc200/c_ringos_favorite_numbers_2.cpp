//ABC_200_C
//Ringo's Favorite Numbers 2
//208
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
	rep(i, n) cin >> a[i];
	vector<ll> d(200,0);
	for (auto ai : a) ++d[ai % 200];
	ll ans = 0;
	for (auto di : d) ans += di * (di - 1) / 2;
	cout << ans << endl;
	return 0;
}