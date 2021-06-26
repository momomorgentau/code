//ABC_201_C
//Secret_Number
//439
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	string s;
	cin >> s;
	vector<char> OK;
	vector<char> NG;
	rep(i, 10)
	{
		if (s[i] == 'o') OK.emplace_back(i+'0');
		else if (s[i] == 'x') NG.emplace_back(i+'0');
	}

	int ans = 0;
	for (int i = 0; i <= 9999; ++i)
	{
		string t = to_string(i);
		while (t.size() < 4) t += '0';
		bool ok = true;
		for (auto o : OK)
		{
			bool tok = false;
			for (auto ti : t) if (ti == o) tok = true;
			if (!tok) ok = false;
		}
		for (auto n : NG)
		{
			for (auto ti : t) if (ti == n) ok = false;
		}
		if (ok) ++ans;
	}
	cout << ans << endl;

	return 0;
}