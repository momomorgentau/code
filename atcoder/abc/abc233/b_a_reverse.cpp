//----------------------------
//ABC_233_B
//A Reverse
//23
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
	int l, r;
	string s;
	cin >> l >> r >> s;
	--l, --r;
	rep(i, s.size())
	{
		int idx = i;
		if (l <= idx && idx <= r)
		{
			idx = r - (idx - l);
		}
		cout << s[idx];
	}
	cout << endl;
	return 0;
}
