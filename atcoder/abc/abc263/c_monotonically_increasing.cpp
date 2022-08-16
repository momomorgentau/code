//----------------------------
//ABC 263 C
//Monotonically Increasing
//298
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int n, m;
void dfs(int p, vector<int> v)
{
	if (v.size() == n)
	{
		rep(i, v.size())
		{
			printf("%d ", v[i]);
		}
		printf("\n");
	}

	reps(i, p + 1, m + 1)
	{
		vector<int> tmp;
		tmp = v;
		tmp.emplace_back(i);
		dfs(i, tmp);
	}
}

int main()
{
	cin >> n >> m;
	vector<int> v;
	dfs(0, v);
	return 0;
}