//034
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, int> mp;
	int cnt = 0;
	queue<int> q;
	int ans = 0;
	int now = 0;
	for (auto ai : a)
	{
		q.emplace(ai);
		++mp[ai];
		if (mp[ai] == 1) ++cnt;
		++now;
		while (cnt > k)
		{
			int m = q.front();
			q.pop();
			--mp[m];
			if (mp[m] == 0) --cnt;
			--now;
		}
		ans = max(ans, now);
	}
	cout << ans << endl;

	return 0;
}