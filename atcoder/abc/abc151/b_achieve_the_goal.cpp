//40
//abc151_b_achieve_the_goal

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	int n, m, k;
	cin >> n >> k >> m;
	int sum = 0;
	rep(i, n - 1)
	{
		int a; cin >> a;
		sum += a;
	}
	int ans = max(0, m * n - sum);
	if (ans > k) ans = -1;
	cout << ans << endl;
	return 0;
}