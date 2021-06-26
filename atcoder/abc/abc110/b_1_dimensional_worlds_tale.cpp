//ABC_110_B
//1_Dimensional_World's_Tale
//?
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int mxx = -1e9;
	int mny = 1e9;
	rep(i, n)
	{
		int xi; cin >> xi;
		mxx = max(mxx, xi);
	}
	rep(i, m)
	{
		int yi; cin >> yi;
		mny = min(mny, yi);
	}
	bool ok = true;
	if (x < mxx + 1 && mny <= y && mxx < mny) cout << "No War" << endl;
	else cout << "War" << endl;
	return 0;
}