//33
//abc142_b_roller_coaster
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	rep(i, n)
	{
		int hi;
		cin >> hi;
		if (hi >= k) ++ans;
	}
	cout << ans << endl;
	return 0;
}
