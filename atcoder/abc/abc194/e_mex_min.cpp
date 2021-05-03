//ABC194E_Mex_Min
//1088
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> h(n+1);
	rep(i, m) ++h[a[i]];
	set<pair<int, int>> s;
	rep(i, n+1)
	{
		s.insert(make_pair(h[i],i));
	}
	int ans = 1e9;
	rep(i, (n - m + 1))
	{
		ans = min((*s.begin()).second, ans);
		if (i == n - m) break;
		int idx1 = i;
		int idx2 = i + m;
		int a1 = a[idx1];
		int a2 = a[idx2];
		s.erase(make_pair(h[a1], a1));
		s.erase(make_pair(h[a2], a2));

		--h[a1];
		++h[a2];
		s.insert(make_pair(h[a1], a1));
		s.insert(make_pair(h[a2], a2));

	}
	cout << ans << endl;

	return 0;
}