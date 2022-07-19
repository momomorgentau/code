//----------------------------
//ABC 260 B
//Better Students Are Needed!	
//195
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
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<P> mth(n);
	vector<P> eng(n);
	vector<P> sum(n);
	rep(i, n)
	{
		cin >> mth[i].first;
		mth[i].second = -i;
	}
	rep(i, n)
	{
		cin >> eng[i].first;
		eng[i].second = -i;
	}
	rep(i, n)
	{
		sum[i].first = mth[i].first + eng[i].first;
		sum[i].second = -i;
	}
	sort(mth.rbegin(), mth.rend());
	sort(eng.rbegin(), eng.rend());
	sort(sum.rbegin(), sum.rend());
	map<int, int> used;
	vector<int> ans;
	rep(i, n)
	{
		if (x <= 0) break;
		if (used[mth[i].second] == 1) continue;
		ans.emplace_back(mth[i].second);
		used[mth[i].second] = 1;
		--x;
	}
	rep(i, n)
	{
		if (y <= 0) break;
		if (used[eng[i].second] == 1) continue;
		ans.emplace_back(eng[i].second);
		used[eng[i].second] = 1;
		--y;
	}
	rep(i, n)
	{
		if (z <= 0) break;
		if (used[sum[i].second] == 1) continue;
		ans.emplace_back(sum[i].second);
		used[sum[i].second] = 1;
		--z;
	}
	sort(ans.rbegin(), ans.rend());
	for (const auto& i : ans) cout << -i + 1 << endl;

	return 0;
}