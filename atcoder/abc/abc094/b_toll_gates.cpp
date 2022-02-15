//----------------------------
//ABC_094_B
//Toll Gates
//128
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
	int n, m, x;
	cin >> n >> m >> x;
	int l = 0;
	int r = 0;
	rep(i, m)
	{
		int ai; cin >> ai;
		if (ai < x) ++l;
		else ++r;
	}
	cout << min(l, r) << endl;
	return 0;
}