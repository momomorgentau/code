//----------------------------
//ABC 264 C
//Matrix Reducing
//758
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int h1, w1;
	cin >> h1 >> w1;
	vector<vector<int>> a(h1, vector<int>(w1));
	rep(i, h1)rep(j, w1) cin >> a[i][j];
	int h2, w2;
	cin >> h2 >> w2;
	vector<vector<int>> b(h2, vector<int>(w2));
	rep(i, h2)rep(j, w2) cin >> b[i][j];

	rep(i, 1 << h1)rep(j, 1 << w1)
	{
		int bit1 = i;
		int bit2 = j;
		int id = 0;
		int jd = 0;

		int cnt = 0;
		bool ok = true;

		int cb1 = 0;
		int cb2 = 0;
		rep(k, h1) if ((bit1 >> k) & 1) cb1++;
		rep(k, w1) if ((bit2 >> k) & 1) cb2++;

		if (h1 - cb1 != h2) continue;
		if (w1 - cb2 != w2) continue;


		rep(l, h1)
		{
			if ((bit1 >> l) & 1) continue;
			int jd = 0;
			rep(m, w1)
			{
				if ((bit2 >> m) & 1) continue;
				if (a[l][m] == b[id][jd])
				{
					++jd;
					++cnt;
				}
				else
				{
					ok = false;
					break;
				}

			}
			if (!ok) break;
			++id;
		}
		if (ok && cnt == w2 * h2)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
