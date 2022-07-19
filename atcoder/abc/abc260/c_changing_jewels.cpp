//----------------------------
//ABC 260 C
//Changing Jewels
//413
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	ll n, x, y;
	cin >> n >> x >> y;
	vector<ll> r(11), b(11);
	r[n] = 1;

	for (int i = n; i > 1; --i)
	{
		r[i - 1] += r[i];
		b[i] += r[i] * x;

		r[i - 1] += b[i];
		b[i - 1] += b[i] * y;
	}
	cout << b[1] << endl;

	return 0;
}