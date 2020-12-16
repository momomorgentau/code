//490
//abc185_d_stamp
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

const int inf = 1e9 + 5;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a{ 0,n + 1 };
	rep(i, m)
	{
		int ai; cin >> ai;
		a.emplace_back(ai);
	}

	sort(a.begin(), a.end());

	int mn = inf;
	vector<int> d(m + 1);

	rep(i, a.size() - 1)
	{
		d[i] = a[i + 1] - a[i] - 1;
		if (d[i] != 0) mn = min(mn, d[i]);
	}
	int ans = 0;
	for (auto di : d)
	{
		ans += (di + mn - 1) / mn;
	}

	cout << ans << endl;
	return 0;
}