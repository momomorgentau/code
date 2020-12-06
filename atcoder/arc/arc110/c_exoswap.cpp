//1100
//arc110_c_exoswap

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> d(n);
	rep(i, n)
	{
		int pi; cin >> pi;
		--pi;
		p[i] = pi;
		d[pi] = i;
	}

	vector<int> ans;
	int idx = 0;
	int pidx = 0;

	bool ok = true;
	while (idx < n - 1 && ok)
	{

		pidx = idx;
		idx = d[pidx];
		if (idx == pidx) ok = false;

		for (int j = idx; j > pidx; --j)
		{
			swap(d[p[j]], d[p[j - 1]]);
			swap(p[j], p[j - 1]);
			ans.emplace_back(j);
		}

		reps(j, pidx, idx)
		{
			if (p[j] != j)
			{
				ok = false;
				break;
			}
		}
	}
	if (ok)
	{
		for (auto a : ans) cout << a << " ";
		cout << endl;
	}
	else cout << -1 << endl;

	return 0;
}