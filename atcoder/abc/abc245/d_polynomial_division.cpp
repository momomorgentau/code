//----------------------------
//ABC 245 D
//Polynomial division
//815
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
	const int INF = 1e9;
	int n, m;
	cin >> n >> m;
	int l = n + m;
	vector<int> a(n + 1), b(m + 1, INF), c(l + 1);
	rep(i, n + 1) cin >> a[i];
	rep(i, l + 1) cin >> c[i];

	for (int k = l; k >= l-(m+1); --k)
	{
		rep(i, n+1)
		{
			int j = k - i;
			if (j < 0 || m < j) continue;
			if (b[j] == INF)
			{
				b[j] = c[k] / a[n];
				break;
			}
			else
			{
				c[k] -= b[j] * a[i];
			}
		}
	}
	rep(i, m + 1) cout << b[i] << " ";
	cout << endl;
	return 0;
}

