//----------------------------
//ABC 262 C
//Min Max Pair
//362
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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) --a[i];
	ll ans = 0;
	ll same = 0;
	rep(i, n)
	{
		if (a[i] == i) ++same;
		else if (a[i] < n && a[a[i]] == i && i < a[i]) ++ans;
	}
	ans += same * (same - 1) / 2;
	cout << ans << endl;
	return 0;
}