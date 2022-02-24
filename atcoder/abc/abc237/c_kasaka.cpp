//----------------------------
//ABC_237_C
//kasaka
//267
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

	int bc = 0;
	rep(i, s.size())
	{
		if (s[i] != 'a')
		{
			break;
		}
		++bc;
	}
	int ec = 0;


	reverse(s.begin(), s.end());
	string t;
	rep(i, s.size())
	{
		if (s[i] == 'a')
		{
			++ec;
			continue;
		}
		t = s.substr(i-min(ec,bc));
		break;
	}
	bool pl = true;
	
	reverse(t.begin(), t.end());
	int sz = t.size();
	rep(i,sz)
	{

		if (t[i] != t[sz-1-i])
		{
			pl = false;
		}
	}
	if (pl) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}