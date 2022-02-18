//----------------------------
//ABC_096_D
//Five. Five Everywhere
//1226
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
	const int M = 55555;
	int n;
	cin >> n;
	vector<int> p;
	vector<int> ans;
	reps(i, 2, M)
	{
		bool ok = true;

		for (const auto& pi : p)
		{
			if (i % pi == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			p.emplace_back(i);
			if (i % 5 == 1)
			{
				ans.emplace_back(i);
			}
			if (ans.size() == n)
			{
				break;
			}
		}
	}
	for (const auto& a : ans)
	{
		cout << a << " ";
	}
	return 0;
}