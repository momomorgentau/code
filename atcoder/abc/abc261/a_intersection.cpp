//----------------------------
//ABC 261 A
//Intersection
//51
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
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	bool on1 = false;
	bool on2 = false;
	int ans = 0;
	rep(i, 105)
	{
		on1 = (l1 <= i && i <= r1);
		on2 = (l2 <= i && i <= r2);
		ans += (on1 && on2);
	}
	cout << max(ans - 1, 0) << endl;
	return 0;
}