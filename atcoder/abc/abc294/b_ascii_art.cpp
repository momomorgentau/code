//----------------------------
//ABC 294 B
//ASCII Art
//25
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	const string t = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int h, w; cin >> h >> w;
	rep(i, h)
	{
		rep(j, w)
		{
			int a; cin >> a;
			cout << t[a];
		}
		cout << endl;
	}
	return 0;
}