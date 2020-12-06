//959
//abc151_maze_master
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

const int inf = 1e9;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];

	int ans = 0;

	rep(si, h)rep(sj, w)
	{
		if (s[si][sj] == '#') continue;

		queue<P> q;
		vector<vector<int>> d(h, vector<int>(w, inf));
		d[si][sj] = 0;
		q.emplace(si, sj);
		while (!q.empty())
		{
			int xi = q.front().first;
			int xj = q.front().second;
			q.pop();
			rep(i, 4)
			{
				int ni = xi + dx[i];
				int nj = xj + dy[i];
				if (ni < 0 || h <= ni) continue;
				if (nj < 0 || w <= nj) continue;
				if (s[ni][nj] == '#') continue;
				if (d[ni][nj] <= d[xi][xj] + 1) continue;
				d[ni][nj] = d[xi][xj] + 1;
				q.emplace(ni, nj);
			}
		}
		rep(i, h)rep(j, w)
		{
			if (s[i][j] == '#') continue;
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << endl;

	return 0;
}