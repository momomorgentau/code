//----------------------------
//ABC 240 D
//Strange Balls
//570
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
	int n;
	cin >> n;
	deque<P> d;
	int a = 0;
	int ans = 0;
	d.emplace_back(-1, -1);
	rep(i, n)
	{
		int a; cin >> a;
		auto [p, c] = d.back();
		++ans;
		if (p == a)
		{
			if (c + 1 == a)
			{
				d.pop_back();
				ans -= c + 1;
			}
			else
			{
				d.pop_back();
				d.emplace_back(a, c + 1);
			}
		}
		else
		{
			d.emplace_back(a, 1);
		}
		cout << ans << endl;

	}
	return 0;
}