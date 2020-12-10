//714
//abc144_d_water_bottle
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	double a, b, x;
	cin >> a >> b >> x;
	double ans;
	if (x <= a * a * b / 2)
	{
		ans = atan(2 * x / (a * b * b));
	}
	else
	{
		ans = atan(a * a * a / (b * a * a - x) / 2);
	}
	ans *= (180.0 / acos(-1.0));
	ans = 90.0 - ans;
	printf("%.7f\n", ans);
	return 0;
}