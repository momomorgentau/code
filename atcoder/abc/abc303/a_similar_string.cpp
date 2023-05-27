//----------------------------
// ABC 303 A 
// Similar String
// 22
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	rep(i,n)
	{
	    if(s[i] == t[i]) continue;
		if(s[i] == '1' || s[i] == 'l')
		{
		    if(t[i] == '1' || t[i] == 'l') continue;
		}
		if(s[i] == '0' || s[i] == 'o')
		{
		    if(t[i] == '0' || t[i] == 'o') continue;
		}
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;

    return 0;
}

