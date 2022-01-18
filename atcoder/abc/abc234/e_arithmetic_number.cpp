//----------------------------
//ABC_234_E
//Arithmetic Number
//899
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
	ll x;
	cin >> x;
	vector<ll> v;
	rep(i, 10)
	{
		rep(j, 10)
		{
			rep(k, 2)
			{
				int ini = j;
				int d = ini;
				string s = to_string(ini);

				while (0 <= d && d <= 9 && s.size() < 19)
				{
					v.emplace_back(stoll(s));
					if (k)
					{
						d += i;
					}
					else
					{
						d -= i;
					}
					s += to_string(d);
				}
			}
		}
	}
	sort(v.begin(), v.end());

	for (const auto& a : v)
	{
		if (a >= x)
		{
			cout << a << endl;
			break;
		}
	}
	return 0;
}