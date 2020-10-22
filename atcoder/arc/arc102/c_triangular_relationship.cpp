//diff 969
//c_triangular_relationship
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	//ifstream in("input.txt");
	//cin.rdbuf(in.rdbuf());

	int n, k;
	cin >> n >> k;
	vector<int> rem(k);
	int nr = n / k;
	int r = n % k;
	rep(i, k)
	{
		rem[i] = nr;
		if (i != 0 && r >= i) ++rem[i];
	}
	ll ans = 0;
	ll k0 = rem[0];
	ans += k0 * k0 * k0;
	if (k % 2 == 0)
	{
		ll k2 = rem[k / 2];
		ans += k2 * k2 * k2;
	}
	cout << ans << endl;
	return 0;
}
