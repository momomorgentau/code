//----------------------------
//ABC_230_B
//Triple_Metre
//37
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
	string t = "oxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";
	bool ok = false;
	rep(i, t.size())
	{
		bool ook = true;
		rep(j, s.size())
		{
			if (i + j >= t.size())
			{
				ook = false;
				break;
			}
			if (s[j] != t[i + j])
			{
				ook = false;
				break;
			}
		}
		if (ook) ok = true;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}