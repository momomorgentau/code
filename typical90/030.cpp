//030
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll ans = 0;
int sz;
int n, k;
vector<int> p;

void dfs(ll m, int cnt, int pos)
{
	if (cnt >= k) ++ans;
	if (m * p[pos] <= n)
	{
		dfs(m * p[pos], cnt, pos);
	}
	for (int i = pos + 1; i < sz; ++i)
	{
		if (m * p[i] > n) return;
		dfs(m * p[i], cnt + 1, i);
	}
};

int main()
{
	cin >> n >> k;
	vector<int> isPrime(n + 1, 1);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (isPrime[i])
		{
			for (int j = 2 * i; j <= n; j += i)
			{
				isPrime[j] = 0;
			}
			p.emplace_back(i);
		}
	}
	sz = p.size();
	rep(i, sz) dfs(p[i], 1, i);
	cout << ans << endl;
	return 0;
}