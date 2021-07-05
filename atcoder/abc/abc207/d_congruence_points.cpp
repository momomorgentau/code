//ABC_207_D
//Congruence_Points
//2074
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using Pd = pair<double, double>;

using namespace std;

const double e = 0.001;

int main()
{
	int n;
	cin >> n;
	vector<Pd> s(n), t(n);
	rep(i, n) cin >> s[i].first >> s[i].second;
	rep(i, n) cin >> t[i].first >> t[i].second;

	if (n == 1)
	{
		cout << "Yes" << endl;
		return 0;
	}
	double tsx = s[0].first;
	double tsy = s[0].second;

	rep(i, n)
	{
		s[i].first -= tsx;
		s[i].second -= tsy;
	}
	double thetaS = atan2(s[1].second, s[1].first);

	rep(i, n)rep(j, n)
	{
		if (i == j) continue;
		vector<Pd> v = t;

		double ttx = v[i].first;
		double tty = v[i].second;

		rep(k, n)
		{
			v[k].first -= ttx;
			v[k].second -= tty;
		}

		double thetaT = atan2(v[j].second, v[j].first);
		double thetaD = thetaS - thetaT;
		rep(k, n)
		{
			double tmp_x = v[k].first;
			double tmp_y = v[k].second;

			v[k].first = tmp_x * cos(thetaD) - tmp_y * sin(thetaD);
			v[k].second = tmp_x * sin(thetaD) + tmp_y * cos(thetaD);
		}

		bool same = true;
		for (auto [sx, sy] : s)
		{
			bool ok = false;
			for (auto [tx, ty] : v)
			{
				if (abs(sx - tx) < e && abs(sy - ty) < e)
				{
					ok = true;
					break;
				}
			}
			if (!ok)
			{
				same = false;
				break;
			}
		}

		if (same)
		{
			cout << "Yes" << endl;
			return 0;
		}

	}
	cout << "No" << endl;
	return 0;
}