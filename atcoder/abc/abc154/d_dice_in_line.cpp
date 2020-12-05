//485
//abc_154_d_dice_in_line
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<(n);++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];

	int sum = 0;
	int mx = 0;
	int mx_idx = 0;
	rep(i, n)
	{
		sum += p[i];
		if (i >= k)
		{
			sum -= p[i - k];
		}
		if (mx < sum)
		{
			mx = sum;
			mx_idx = i - k + 1;
		}
	}
	double ans = 0;
	reps(i, mx_idx, mx_idx + k)
	{
		ans += ((double)p[i] * ((double)p[i] + 1) / 2) / p[i];
	}
	printf("%.7f\n", ans);
	return 0;
}

