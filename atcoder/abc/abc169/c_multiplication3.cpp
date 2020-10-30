//528
//abc169_multiplication3
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll a;
	double b;
	cin >> a >> b;
	ll b2 = b * 100 + 0.01;
	ll ans = (a * b2) / 100;

	cout << ans << endl;
	return 0;
}
