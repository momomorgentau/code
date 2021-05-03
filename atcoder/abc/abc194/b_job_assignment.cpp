//ABC194B_Job_Assignment
//104
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
	int ans = 1e9;
	rep(i, n)rep(j, n)
	{
		if (i == j) ans = min(a[i] + b[i], ans);
		else
		{
			ans = min(max(a[i], b[j]), ans);
		}
	}
	cout << ans << endl;
	return 0;
}