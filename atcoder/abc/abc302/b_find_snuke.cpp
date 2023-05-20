//----------------------------
// ABC 302 B
// Find snuke
// 352
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int h, w;
vector<string> s;

int main()
{
	cin >> h >> w;
	s.resize(h);
	rep(i, h) cin >> s[i];
	vector<int> dx = { 0,1,1,1,0,-1,-1,-1 };
	vector<int> dy = { -1,-1,0,1,1,1,0,-1 };

	string t = "snuke";
	rep(y, h)rep(x, w)
	{
		rep(i, 8)
		{
			int cy = y;
			int cx = x;
			bool ok = true;
			rep(j, 5)
			{
				if (cy < 0 || h <= cy) ok = false;
				if (cx < 0 || w <= cx) ok = false;
				if (!ok) break;
				if (s[cy][cx] != t[j]) ok = false;
				cy += dy[i];
				cx += dx[i];
			}
			if (ok)
			{
				int ay = y;
				int ax = x;
				rep(j, 5)
				{
					cout << ay + 1 << " " << ax + 1 << endl;
					ay += dy[i];
					ax += dx[i];
				}
				return 0;
			}
		}
	}
	return 0;
}

