//----------------------------
//ABC 241 C
//Connect 6
//664
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
	int n; cin >> n;
	vector<string> g(n);
	rep(i, n) cin >> g[i];
	bool ok = false;
	rep(h, n)rep(w, n)
	{
		{
			int count = 0;
			bool tmp = true;
			rep(i, 6)
			{
				int nh = h + i;
				int nw = w;
				if (nh >= n || nw >= n)
				{
					tmp = false;
					continue;
				}
				if (g[nh][nw] == '.')
				{
					++count;
				}
			}
			if (count > 2)tmp = false;
			if (tmp) ok = true;
		}
		{
			int count = 0;
			bool tmp = true;
			rep(i, 6)
			{
				int nh = h;
				int nw = w + i;
				if (nh >= n || nw >= n)
				{
					tmp = false;
					continue;
				}
				if (g[nh][nw] == '.')
				{
					++count;
				}
			}
			if (count > 2)tmp = false;
			if (tmp) ok = true;
		}
		{
			int count = 0;
			bool tmp = true;
			rep(i, 6)
			{
				int nh = h + i;
				int nw = w + i;
				if (nh >= n || nw >= n)
				{
					tmp = false;
					continue;
				}
				if (g[nh][nw] == '.')
				{
					++count;
				}
			}
			if (count > 2)tmp = false;
			if (tmp) ok = true;
		}

		{
			int count = 0;
			bool tmp = true;
			rep(i, 6)
			{
				int nh = h - i;
				int nw = w + i;
				if (nh < 0 || n <= nw)
				{
					tmp = false;
					continue;
				}
				if (g[nh][nw] == '.')
				{
					++count;
				}
			}
			if (count > 2)tmp = false;
			if (tmp) ok = true;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
