//----------------------------
// ABC 303 C 
// Dash
// 417
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n,m,h,k;
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;
	map<P,int> mp;
	rep(i,m)
	{
	    int x,y;
		cin >> x >> y;
		mp[make_pair(x,y)] = 1;
	}
	int x = 0;
	int y = 0;
	int count = 0;
	for(const auto&c:s)
	{
		if(c == 'R') x++;
		if(c == 'L') x--;
		if(c == 'U') y++;
		if(c == 'D') y--;
		h--;
		if(h < 0)
		{
		    cout << "No" << endl;
			return 0;
		}
		if(mp.count(make_pair(x,y)) && mp[make_pair(x,y)] == 1)
		{
		    if(h >= k) continue;
		    h = max(h,k);
			mp[make_pair(x,y)] = 0;
		}
	}
	cout << "Yes" << endl;
    return 0;
}

