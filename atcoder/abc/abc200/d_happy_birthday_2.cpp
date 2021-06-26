//ABC_200_D
//Happy Birthday! 2
//1217
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int mod = 200;
int dp[205][205];
vector<int> a;

vector<vector<int>> ans(200);
vector<int> ans1;
int R = -1;
int n;
void dfs(vector<int> v,int rem,int pos)
{
	int cnt = v.size();
	vector<int> tmp = v;
	tmp.emplace_back(pos+1);
	int now = (rem + a[pos]) % mod;
	if (ans[now].size() == 0)
	{
		for(auto t:tmp) ans[now].emplace_back(t);
	}
	else
	{
		ans1 = tmp;
		R = now;
		return;
	}
	if (pos + 1 == n) return;
	dfs(v, rem, pos + 1);
	dfs(tmp, now, pos + 1);
	return;
}
int main()
{
	cin >> n;
	a.resize(n);
	rep(i,n) cin >> a[i];
	rep(i, n) a[i] %= mod;

	vector<int> v;
	dfs(v, 0, 0);
	
	if (ans1.size() == 0)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		cout << ans[R].size() << " ";
		for (auto ai : ans[R]) cout << ai << " ";
		cout << endl;
		cout << ans1.size() << " ";
		for (auto ai : ans1) cout << ai << " ";
		cout << endl;
	}

	
	return 0;
}