//043
//Maze_Challenge_with_Lack_of_Sleep
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF = 1e9;
const int H = 1000;
const int W = 1000;
int d[H + 5][W + 5][4];

int main()
{
	int h, w;
	int sx, sy, tx, ty;
	cin >> h >> w >> sy >> sx >> ty >>tx;
	--sx, --sy, --tx, --ty;
	vector<string> g(h);
	rep(i, h) cin >> g[i];
	rep(i, H + 5)rep(j, W + 5)rep(k, 4) d[i][j][k] = INF;
	rep(i, 4) d[sy][sx][i] = 0;
	queue<tuple<int, int,int>> q;
	rep(i,4) q.emplace(sx, sy, i);

	vector<int> dx = {0,0,-1,1};
	vector<int> dy = {1,-1,0,0 };

	while (!q.empty())
	{
		int x, y, dir;
		tie(x, y, dir) = q.front();
		q.pop();
		
		rep(i, 4)
	    {
			int nx = x + dx[i];
		    int ny = y + dy[i];
			if (nx < 0 || w <= nx) continue;
			if (ny < 0 || h <= ny) continue;
			if (g[ny][nx] == '#') continue;

			if (dir == i)
			{
				if (d[ny][nx][dir] <= d[y][x][dir]) continue;
				d[ny][nx][dir] = d[y][x][dir];
			}
			else
			{
				if (d[ny][nx][i] <= d[y][x][dir] + 1)continue;
				d[ny][nx][i] = d[y][x][dir]+1;
			}
			q.emplace(nx,ny,i);
		}
		
	}
	int ans = INF;
	rep(i, 4) ans = min(ans,d[ty][tx][i]);
	cout << ans << endl;



	return 0;
}