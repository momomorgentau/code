//----------------------------
// ABC 320 B 
// Longest Palindrome
// 84
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
	cin >> s;
	int size = s.size();
	int ans = 0;
	rep(i,size)rep(j,size)
	{
	    if(i > j) continue;
		int l = j -i +1;
		bool ok = true;
		rep(k, l)
		{
		    if(s[i+k] == s[i+l-k-1]) continue;
			ok = false;
			break;
		}
		if(ok)
		{
		    ans = max(ans, l);
		}

	}
	cout << ans << endl;
    return 0;
}

