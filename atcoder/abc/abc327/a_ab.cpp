//----------------------------
// ABC 327 A 
// ab
// 23
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string s;
	int n;
	cin >> n >> s;
	bool ok = false;
	rep(i,n-1)
	{
	    ok |= s[i] == 'a' && s[i+1] == 'b';
	    ok |= s[i] == 'b' && s[i+1] == 'a';
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	
    return 0;
}

