//----------------------------
//ABC_096_C
//Gripd Repainting 2
//407
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
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	bool ok = true;
	vector<int> dx{ 0,0,-1,1 };
	vector<int> dy{ 1,-1,0,0 };
	rep(i, h)rep(j, w)
	{
		if (s[i][j] == '.') continue;
		bool tok = false;
		rep(k, 4)
		{
			int nx = j + dx[k];
			int ny = i + dy[k];
			if (nx < 0 || w <= nx) continue;
			if (ny < 0 || h <= ny) continue;
			if (s[ny][nx] == '#')
			{
				tok = true;
			}
		}
		if (tok) continue;
		ok = false;
		break;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}