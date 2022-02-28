//----------------------------
//ABC 232 D
//Weak Takahashi 
//539
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
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	rep(i, h)cin >> g[i];
	vector<vector<int>> d(h, vector<int>(w, -1));
	queue<P> q;
	q.emplace(make_pair(0, 0));
	d[0][0] = 1;
	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();
		if (x + 1 < w)
		{

			if (d[y][x + 1] != 1 && g[y][x + 1] != '#')
			{
				d[y][x + 1] = 1;
				q.emplace(make_pair(y, x + 1));
			}
		}
		if (y + 1 < h)
		{

			if (d[y + 1][x] != 1 && g[y + 1][x] != '#')
			{
				d[y + 1][x] = 1;
				q.emplace(make_pair(y + 1, x));
			}
		}
	}
	int ans = 1;
	rep(i, h)rep(j, w)
	{
		if (d[i][j] == 1)
		{
			ans = max(ans, i + j + 1);
		}
	}
	cout << ans << endl;
	return 0;
}