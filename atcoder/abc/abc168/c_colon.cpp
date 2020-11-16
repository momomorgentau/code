//107
//abc168_c_colon
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

const double pi = M_PI;

int main()
{
	double a, b, h, m;
	cin >> a >> b >> h >> m;

	double tm = m * pi / 30;
	double th = m * pi / 360 + h * pi / 6;
	double dt = th - tm;

	double ta = a * a + b * b -2 * a * b * cos(dt);
	double ans = sqrt(ta);

	cout << setprecision(10);
	cout << ans << endl;
	return 0;
}