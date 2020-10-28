//97
//abc179c_forbidden_list
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main()
{
	int x, n;
	cin >> x >> n;
	set<int> p;
	rep(i, n)
	{
		int tp; cin >> tp;
		p.emplace(tp);
	}
	int d = 0;

	while (1)
	{
		if (!p.count(x - d))
		{
			cout << x - d << endl;
			return 0;
		}
		if (!p.count(x + d))
		{
			cout << x + d << endl;
			return 0;
		}
		++d;
	}
	return 0;
}