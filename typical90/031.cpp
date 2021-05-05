//031
//*6
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int W = 50;
const int B = 1400;

int grundy[W + 5][B + 5];


int main()
{
	rep(i, W + 1)reps(j, 0, B)
	{
		vector<int> mex(B, -1);
		if (j >= 2)
		{
			for (int k = j - 1; k >= j - (j / 2); --k)
			{
				mex[grundy[i][k]] = 1;
			}
		}
		if (i >= 1) mex[grundy[i - 1][j + i]] = 1;
		rep(k, B)
		{
			if (mex[k] == -1)
			{
				grundy[i][j] = k;
				break;
			}
		}
	}
	int n;
	cin >> n;
	vector<int> w(n), b(n);
	rep(i, n) cin >> w[i];
	rep(i, n) cin >> b[i];
	int ans = 0;
	rep(i, n) ans ^= grundy[w[i]][b[i]];

	if (ans != 0) cout << "First" << endl;
	else cout << "Second" << endl;

	return 0;
}