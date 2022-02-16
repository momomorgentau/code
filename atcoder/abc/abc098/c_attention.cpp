//----------------------------
//ABC_098_C
//Many Medians
//635
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
	string s;
	cin >> n >> s;
	vector<int> w(n), e(n);
	
	rep(i,n)
	{
		char c = s[i];
			
		if(c == 'W')
		{
			w[i]++;
		}
		if (i < n - 1)
		{
		    w[i + 1] += w[i];
		}
	}
	rep(i, n)
	{
		int idx = n - 1 - i;
		char c = s[idx];
		if (c == 'E')
		{
			e[idx]++;
		}
		if (0 < idx)
		{
			e[idx - 1] += e[idx];
		}
	}

	int ans = 1e9;
	rep(i, n)
	{
		int now = w[i] + e[i] -1;
		ans = min(ans, now);
	}
	cout << ans << endl;
}