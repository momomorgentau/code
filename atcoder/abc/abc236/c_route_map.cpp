//----------------------------
//ABC 236 C
//Route Map
//80
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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	set<string> st;
	rep(i, m)
	{
		string t;
		cin >> t;
		st.insert(t);
	}
	for (const auto& si : s)
	{
		if (st.count(si)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}