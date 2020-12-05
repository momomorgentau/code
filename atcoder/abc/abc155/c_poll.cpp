//236
//abc_155_c_poll
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<string> s(n);
	map<string, int> sm;
	rep(i, n)
	{
		cin >> s[i];
		++sm[s[i]];
	}
	int mx = 0;
	for (auto smi : sm)
	{
		int cnt;
		tie(ignore, cnt) = smi;
		mx = max(mx, cnt);
	}
	vector<string> ans;
	for (auto smi : sm)
	{
		int cnt;
		string si;
		tie(si, cnt) = smi;
		if (cnt == mx) ans.emplace_back(si);
	}
	sort(ans.begin(), ans.end());
	for (auto a : ans) cout << a << endl;

	return 0;
}
