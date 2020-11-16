//1356
//abc169_e_count_median

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i, n) cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans = 0;
	if (n & 1) 
	{
	    int m = (n+1) / 2;
		ans = b[n - m] - a[m-1] +1;
	}
	else
	{
		int m1 = (n / 2);
		int m2 = m1 + 1;

		int l1 = a[m1 - 1];
		int r1 = b[n - m2];
		int l2 = a[m2 - 1];
		int r2 = b[n - m1];

		ans = (r1 + r2) - (l1 + l2) + 1;
	}
	
	cout << ans << endl;
	return 0;
}
