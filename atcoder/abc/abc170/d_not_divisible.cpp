//1034
//abc170d_not_divisible
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;

const int nm = 1e6 + 5;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> na(nm, 0);
	set<int> sn; //“¯‚¶”Žš‚ª•¡”“oê‚µ‚½Û‚É‚‘¬‰»‚·‚éB–³‚¢‚ÆTLE‚µ‚Ü‚·B

	rep(i, n)
	{
		int ta; cin >> ta;
		a[i] = ta;
		if (sn.count(ta))
		{
			++na[ta];
			continue;
		}
		sn.emplace(ta);
		for (ll i = ta; i < nm; i += ta) ++na[i];
	}

	int ans = 0;
	rep(i, n) if (na[a[i]] == 1) ++ans;
	cout << ans << endl;
	return 0;
}