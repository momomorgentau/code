//diff 600
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int h, w, k;
	cin >> h >> w >> k;
	vector<int> x(w, 0), y(h, 0);
	set<P> s;
	int b = 0;
	rep(i, h) rep(j, w) {
		char a;
		cin >> a;
		if (a == '#')
		{
			++x[j];
			++y[i];
			s.emplace(i, j);
			++b;
		}
	}

	int ans = 0;
	rep(hi, 1 << h)rep(wj, 1 << w)
	{
		int cnt = 0;
		rep(i, h)
		{
			int by = 1 << i;
			if (by & hi) cnt += y[i];
		}
		rep(j, w)
		{
			int bx = 1 << j;
			if (bx & wj) cnt += x[j];
		}

		rep(i, h)rep(j, w)
		{
			int by = 1 << i;
			int bx = 1 << j;
			if (by & hi && bx & wj)
			{
				P pii;
				pii.first = i;
				pii.second = j;
				if (s.count(pii)) --cnt;
			}
		}
		if (b - cnt == k) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}