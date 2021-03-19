//ABC194D_Journey
//1078
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	double ans = -1.0;
	rep(i, n)
	{
		ans += (double)n / (double)(n - i);
	}
	printf("%.7f\n", ans);

	return 0;
}