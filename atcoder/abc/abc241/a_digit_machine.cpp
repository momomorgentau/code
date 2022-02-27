//----------------------------
//ABC 241 A
//Digit Machine
//15
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
	vector<int> a(10);
	rep(i, 10) cin >> a[i];
	int ans = 0;
	rep(i, 3)
	{
		ans = a[ans];
	}
	cout << ans << endl;
	return 0;
}