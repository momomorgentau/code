//----------------------------
// ABC 295 B
// Bombs
// 156
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int r, c;
	cin >> r >> c;
	vector<string> g(r);
	rep(i, r) cin >> g[i];
	vector<string> s;
	s = g;
	rep(i, r)rep(j, c)
	{
		if (g[i][j] == '.' || g[i][j] == '#')
		{
			continue;
		}
		int d = g[i][j] - '0';
		for (int x = -d; x <= d; x++)
		{
			for (int y = -d; y <= d; y++)
			{
				if (abs(x) + abs(y) > d) continue;
				if (i + y < 0 || r <= i + y) continue;
				if (j + x < 0 || c <= j + x) continue;
				s[i + y][j + x] = '.';
			}
		}
	}
	for (const auto& v : s)
	{
		for (const auto& a : v)
		{
			cout << a;
		}
		cout << endl;
	}

	return 0;
}