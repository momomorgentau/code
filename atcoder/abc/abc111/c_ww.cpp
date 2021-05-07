//ABC_111_C
// /\/\/\/
//826
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	unordered_map<int, int> odd, even;
	for (int i = 0; i < n; i += 2) ++even[v[i]];
	for (int i = 1; i < n; i += 2) ++odd[v[i]];
	pair<int, int> o1, o2, e1, e2;
	o1 = make_pair(-1, 0);
	o2 = make_pair(-1, 0);
	e1 = make_pair(-1, 0);
	e2 = make_pair(-1, 0);

	for (auto [c, num] : odd)
	{
		if (num >= o1.second)
		{
			o2.first = o1.first;
			o2.second = o1.second;
			o1.first = c;
			o1.second = num;
		}
		else if (num >= o2.second)
		{
			o2.first = c;
			o2.second = num;
		}
	}
	for (auto [c, num] : even)
	{
		if (num >= e1.second)
		{

			e2.first = e1.first;
			e2.second = e1.second;
			e1.first = c;
			e1.second = num;
		}
		else if (num >= e2.second)
		{
			e2.first = c;
			e2.second = num;
		}
	}
	int ans = 1e9;
	if (o1.first != e1.first) ans = n - o1.second - e1.second;
	else
	{
		ans = n - max(o1.second + e2.second, o2.second + e1.second);
	}
	cout << ans << endl;
	return 0;
}