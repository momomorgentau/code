//333
//abc151_c_welcome_to_atcoder
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(m);
	vector<string> s(m);
	rep(i, m) cin >> p[i] >> s[i];
	rep(i, m) --p[i];
	vector<bool> aced(n);
	int ac = 0;
	int wa = 0;
	map<int, int> twa;
	rep(i, m)
	{
		if (aced[p[i]]) continue;
		if (s[i] == "AC")
		{
			++ac;
			wa += twa[p[i]];
			aced[p[i]] = true;
		}
		else ++twa[p[i]];
	}
	cout << ac << " " << wa << endl;


	return 0;
}