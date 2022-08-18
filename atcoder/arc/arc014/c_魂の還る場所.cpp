//ARC 014 C
//ŒN‚ª–]‚Ş‚È‚ç¢ŠE’†‘S‚Ä‚Ì‚½‚±Ä‚«‚ğÔ‚ÆÂ‚Éõ‚ßã‚°‚æ‚¤
//1266
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	set<string> p;
	p.emplace("");
	for (const auto& c : s)
	{
		set<string> q;
		for (const auto& pi : p)
		{
			int sz = pi.size();
			if (sz == 0)
			{
				q.insert({ c });
				continue;
			}

			if (sz == 1)
			{
				if (pi[0] == c)
				{
					q.emplace("");
				}
				else
				{
					q.emplace(pi + c);
					q.emplace(c + pi);
				}
				continue;
			}
			bool l = (pi[0] == c);
			bool r = (pi[sz - 1] == c);
			if (l && r)
			{
				q.emplace(pi.substr(1, sz - 1));
				q.emplace(pi.substr(0, sz - 1));
				continue;
			}
			if (l)
			{
				q.emplace(pi.substr(1, sz - 1));
				continue;
			}
			if (r)
			{
				q.emplace(pi.substr(0, sz - 1));
				continue;
			}

			q.emplace(c + pi);
			q.emplace(pi + c);

		}
		swap(p, q);
	}
	int ans = 100;
	for (const auto& pi : p)ans = min(ans, (int)pi.size());
	cout << ans << endl;
	return 0;
}