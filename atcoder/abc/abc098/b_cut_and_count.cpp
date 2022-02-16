//----------------------------
//ABC_098_B
//Cut ans Count
//360
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
	map<char, int> mpl,mpr;
	for (const auto& c : s)
	{
		mpr[c]++;
	}
	int ans = 0;
	for (const auto& c : s)
	{
		mpl[c]++;
		mpr[c]--;
		int now = 0;
		for (const auto& si : "abcdefghijklmnopqrstuvwxyz")
		{
			if (mpl[si] > 0 && mpr[si] > 0)
			{
				++now;
			}
		}
		ans = max(ans, now);
	}
	cout << ans << endl;
}