//ABC_110_C
//String_Transformation
//949
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	string s, t;
	cin >> s >> t;
	bool ok = true;
	rep(i, 26)
	{
		char c = i + 'a';
		char cs = 'X';
		rep(j, s.size())
		{
			if (t[j] == c)
			{
				if (cs == 'X') cs = s[j];
				if (s[j] != cs) ok = false;
			}
			else
			{
				if (s[j] == cs) ok = false;
			}
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}