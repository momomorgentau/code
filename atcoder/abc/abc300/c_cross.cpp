//----------------------------
// ABC 300 C 
// Cross
// 534
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> used(h, vector<int> (w));
	queue<P> q;
	int mn = min(h, w);
	map<int,int> mp;
	vector<int> dx = { -1,-1,1,1 };
	vector<int> dy = { -1,1,1,-1 };
	rep(i, h)rep(j, w)
	{
		if (used[i][j]) continue;
		if (s[i][j] == '.') continue;
		used[i][j] = 1;
		q.emplace(make_pair(i, j));
		int count = 1;
		while (!q.empty())
		{
			auto [y, x] = q.front();
			q.pop();
			rep(k, 4)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 0 || h <= ny) continue;
				if (nx < 0 || w <= nx) continue;
				if (s[ny][nx] == '.') continue;
				if (used[ny][nx]) continue;

				used[ny][nx] = 1;
				count++;
				q.emplace(make_pair(ny, nx));
			}
		}
		mp[count]++;
	}
	rep(i, mn)
	{
		cout << mp[4 * (i + 1) + 1] << " ";
	}

	return 0;
}
