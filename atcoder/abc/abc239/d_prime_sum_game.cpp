//----------------------------
//ABC_239_D
//Prime Sum Game
//252
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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> p;
	for (int i = 2; i <= 200; ++i)
	{
		bool is_p = true;
		for (const auto& pi : p)
		{
			if (i % pi == 0)
			{
				is_p = false;
				break;
			}
		}
		if (is_p) p.emplace_back(i);
	}
	bool takahashi = false;
	for (int i = a; i <= b; ++i)
	{
		bool tmp = true;
		for (int j = c; j <= d; ++j)
		{
			int tp = i + j;
			for (const auto& pi : p)
			{
				if (tp == pi)
				{
					tmp = false;
				}
			}
		}
		if (tmp)
		{
			takahashi = true;
			break;
		}
	}
	if (takahashi) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;

}