//----------------------------
//ABC_233_A
//10yen Stamp
//9
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
	int x, y;
	cin >> x >> y;
	if (x >= y)
	{
		cout << "0" << endl;
		return 0;
	}
	int ans = (y - x) / 10;
	if ((y - x) % 10 != 0)
	{
		++ans;
	}
	cout << ans << endl;
	return 0;
}