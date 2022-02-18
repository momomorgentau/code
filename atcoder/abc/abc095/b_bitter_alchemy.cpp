//----------------------------
//ABC_095_B
//Bitter Alchemy
//82
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
	int n, x;
	cin >> n >> x;
	int mn = 1e9;
	rep(i, n)
	{
		int m; cin >> m;
		x -= m;
		mn = min(mn, m);
	}
	int ans = n + x / mn;
	cout << ans << endl;
}