//129
//abc_153_d_caracal_vs_monster
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	ll h;
	cin >> h;
	ll ans = 0;
	ll d = 1;
	while (h > 0)
	{
		ans += d;
		d *= 2;
		h /= 2;
	}
	cout << ans << endl;
	return 0;
}