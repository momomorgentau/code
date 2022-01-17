//----------------------------
//ABC_235_D
//Multiplay and Rotate
//862
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


const int LIMIT = 1e7;
const int INF = 1e9;

int main()
{
	ll a, n;
	cin >> a >> n;
	queue<pair<ll, int>> q;
	q.emplace(make_pair(1LL, 0));
	unordered_map<int, int> mp;

	int ans = INF;

	while (!q.empty())
	{

		auto [x, t] = q.front();
		q.pop();
		if (x == n)
		{
			ans = min(ans, t);
			continue;
		}
		if (x * a < LIMIT && !mp[x * a])
		{
			mp[x * a] = 1;
			q.emplace(make_pair(x * a, t + 1));
		}
		if (x >= 10 && x % 10 != 0)
		{
			string s = to_string(x);
			int sz = s.size();
			s = s[sz - 1] + s.substr(0, sz - 1);
			ll tmp = stoll(s);
			if (!mp[tmp])
			{
				mp[tmp] = 1;
				q.emplace(make_pair(tmp, t + 1));
			}
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}