//----------------------------
//ABC 260 A
//A Unique Letter
//12
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
	string ans = "";
	if (s[0] != s[1] && s[0] != s[2])
	{
		cout << s[0] << endl;
		return 0;
	}
	if (s[1] != s[0] && s[1] != s[2])
	{
		cout << s[1] << endl;
		return 0;
	}
	if (s[2] != s[0] && s[2] != s[1])
	{
		cout << s[2] << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}