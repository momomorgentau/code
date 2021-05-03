//ABC_193_D_Poker
//866
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll k;
string s, t;

int score(vector<int> &v, int m)
{
	vector<int> tv = v;
	tv[m]++;
	int res = 0;
	for (int i = 1; i <= 9; ++i)
	{
		res += i * (int)pow(10,tv[i]);
	}
	return res;
}

int main()
{

	cin >> k >> s >> t;
	double ans = 0;
	vector<int> sh(10);
	vector<int> th(10);
	vector<int> zh(10);

	rep(i, 4) ++sh[s[i] - '0'];
	rep(i, 4) ++th[t[i] - '0'];
	rep(i, 10) zh[i] = sh[i] + th[i];


	for (int i = 1; i <= 9; ++i)
	{
		if (k - zh[i] == 0) continue;
		int s1 = score(sh,i);
		for (int j = 1; j <= 9; ++j)
		{
			if (k - th[j] - (i == j) <= 0) continue;
			int s2 = score(th, j);
			if (s1 <= s2) continue;
			double p1 = (double)(k - zh[i]) / (double)(9 * k - 8);
			double p2 = (double)(k - zh[j] - (i == j)) / (double)(9 * k - 9);
			ans += p1 * p2;
		}
	}
	cout << ans << endl;


}