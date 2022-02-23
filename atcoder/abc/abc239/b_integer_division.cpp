//----------------------------
//ABC_239_B
//Integer Division
//57
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
	ll x;
	cin >> x;
	ll ans = 0;
	if (x %10 == 0)
	{
		ans = x / 10;
	}
	else
	{
		if (x < 0)
		{
			x -= 10;
		}
		ans = x / 10;
	}
	cout << ans << endl;
}