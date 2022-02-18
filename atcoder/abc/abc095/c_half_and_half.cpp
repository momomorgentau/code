//----------------------------
//ABC_095_C
//Half and Half
//291
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
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 1e9;
	{
		int now = a * x + b * y;
		ans = min(ans,now);
	}
	{
		int now = x * 2 * c + max(0, y - x) * b;
		ans = min(ans, now);
	}
	{
		int now = max(0,x-y) * a + y * 2 * c;
		ans = min(ans, now);
	}
	cout << ans << endl;
}