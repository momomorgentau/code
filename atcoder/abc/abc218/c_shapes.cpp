//----------------------------
//ABC_218_C
//Shapes
//1012
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
	vector<P> s, t;
	rep(i, n)
	{
		string si; cin >> si;
		rep(j, n)
		{
			if (si[j] == '#')
			{
				s.emplace_back(i, j);
			}
		}
	}
	rep(i, n)
	{
		string si; cin >> si;
		rep(j, n)
		{
			if (si[j] == '#')
			{
				t.emplace_back(i, j);
			}
		}
	}

	if (s.size() != t.size())
	{
		cout << "No" << endl;
		return 0;
	}

	bool ok = false;
	rep(i, 4)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		int dx = s[0].first - t[0].first;
		int dy = s[0].second - t[0].second;
		bool tok = true;
		rep(j, s.size())
		{
			if (s[j].first - t[j].first != dx
				|| s[j].second - t[j].second != dy)
			{
				tok = false;
				break;
			}
		}
		if (tok)
		{
			ok = true;
			break;
		}

		for (auto& [x, y] : s)
		{
			swap(x, y);
			x *= -1;
		}

	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;



	return 0;
}