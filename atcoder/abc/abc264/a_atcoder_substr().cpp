//----------------------------
//ABC 264 A
//"atcoder".substr()
//8
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	string s = "atcoder";
	int l, r;
	cin >> l >> r;
	for (int i = l - 1; i < r; ++i)
	{
		cout << s[i];
	}
	return 0;
}