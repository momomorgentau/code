//----------------------------
//ABC_240_C
//Jumping Takahashi
//464
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
	int n, x;
	cin >> n >> x;
	vector<int> d(x + 5, 0);
	d[0] = 1;
	rep(i, n)
	{
		vector<int> e(x + 5, 0);

		int a, b;
		cin >> a >> b;
		rep(j, x)
		{
			if (d[j] == 0) continue;
			int na = min(x + 1, j + a);
			int nb = min(x + 1, j + b);
			e[na] = 1;
			e[nb] = 1;
		}
		swap(e, d);
	}
	if (d[x] == 1) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}