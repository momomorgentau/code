//----------------------------
// ABC 301 E 
// Pac-Takahashi
// 
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int M = 20;

int main()
{
    int h,w,t;
    cin >> h >> w >> t;
    vector<string> a(h);
	rep(i,h) cin >> a[i];
	const int INF = 1e9;
	vector<vector<int>> g(M,vector<int> (M,INF));
	rep(i,M) g[i][i] = 0;
	map<int, int> mp;
	int count = 2;
	rep(i,h)rep(j,w)
	{
	    if(a[i][j] == '.') continue;
		if(a[i][j] == 'S') mp[i*w+j] = 0;
		if(a[i][j] == 'G') mp[i*w+j] = 1;
		if(a[i][j] == 'o') mp[i*w+j] = count++; 
	}

	for(const auto&[yx,val]:mp)
	{
	    int y = yx / w;
		int x = yx % w;
		queue<int> q;
		vector<int> dx = {0,0,-1,1};
		vector<int> dy = {-1,1,0,0};
		vector<vector<int>> used(h,vector<int> (w,INF));
		used[y][x] = 0;
		q.emplace(yx);
		while(!q.empty())
		{
		    int cyx = q.front();
			q.pop();
		    int cx = cyx % w;
			int cy = cyx / w;
			rep(j,4)
			{
			   int ncx = cx + dx[j];
			   int ncy = cy + dy[j];
			   if(ncx < 0 || w <= ncx) continue;
			   if(ncy < 0 || h <= ncy) continue;
			   if(a[ncy][ncx] == '#') continue;
			   if(used[ncy][ncx] != INF) continue;
			   used[ncy][ncx] = used[cy][cx] + 1;
			   int ncyx = ncy * w + ncx;
			   if(mp.count(ncyx))
			   {
			       g[val][mp[ncyx]] = used[ncy][ncx];
			   }
			   q.emplace(ncyx);
			}
		}

	}
    vector<vector<int>> dp(M,vector<int> (1<<M,INF));
	dp[0][1] = 0;
	rep(i, 1<<M)
	{
	    rep(j, M) rep(k,M)
		{
		    if(!((i >> j) & 1)) continue;
			if((i >> k) & 1) continue;
			dp[k][i|(1<<k)] = min(dp[k][i|(1<<k)], dp[j][i]+g[j][k]);
		}
	}
	int ans = -1;
	rep(i,1<<M)
	{
	    if(dp[1][i] <= t)
		{
		    int now = -2;
			rep(j, M) now += ((i >> j) & 1);
		
	    	ans = max(ans,now);
        }
	}
	cout << ans << endl;





    return 0;
}

