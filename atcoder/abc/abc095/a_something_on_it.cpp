//----------------------------
//ABC_095_A
//Something on It
//22
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
	cin >> s;
	int ans = 700;
	for (const auto& c : s)
	{
		if (c == 'o')
		{
			ans += 100;
		}
	}
	cout << ans << endl;
}