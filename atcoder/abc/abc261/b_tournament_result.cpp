//----------------------------
//ABC 261 B
//Tournament Result
//74
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
	int n; cin >> n;
	vector<string> a(n);
	rep(i, n)cin >> a[i];
	bool ng = false;
	map<char, int> mp;
	mp['L'] = 0;
	mp['D'] = 1;
	mp['W'] = 2;
	rep(i, n)rep(j, n)
	{
		if (i == j) continue;
		ng |= (mp[a[i][j]] + mp[a[j][i]] != 2);
	}
	if (ng) cout << "incorrect" << endl;
	else cout << "correct" << endl;
	return 0;
}