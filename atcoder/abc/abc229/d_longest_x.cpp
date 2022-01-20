//----------------------------
//ABC_229_D
//Longest X
//745
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
	string s;
	int k;
	cin >> s >> k;
	queue<char> q, p;
	for (const auto& c : s)
	{
		q.emplace(c);
	}
	int ans = 0;
	int now = 0;
	while (!q.empty())
	{
		char c = q.front();
		q.pop();
		p.emplace(c);
		if (c == '.')
		{
			--k;
		}
		while (k < 0)
		{
			char d = p.front();
			p.pop();
			if (d == '.')
			{
				++k;
			}
		}

		ans = max(ans, int(p.size()));
	}
	cout << ans << endl;
	return 0;
}