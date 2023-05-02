//----------------------------
// ABC 300 B 
// Same Map in the RPG World
// 353
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
		vector<string> a(h), b(h);
		rep(i, h) cin >> a[i];
		rep(i, h) cin >> b[i];
		rep(i, h)rep(j, w)
		{
				vector<string> tmp;
				tmp = a;
				rep(y, h)rep(x, w)
				{
						tmp[(y + i) % h][(x + j) % w] = a[y][x];
				}
				bool ok = true;
				rep(ii, h)rep(jj, w)
				{
						if (tmp[ii][jj] != b[ii][jj])
						{
								ok = false;
						}
				}
				if (ok)
				{
						cout << "Yes" << endl;
						return 0;
				}
		}
		cout << "No" << endl;
		return 0;
}
