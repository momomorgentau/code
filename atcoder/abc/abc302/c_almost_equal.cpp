//----------------------------
// ABC 302 C 
// Almost Equal
// 469:
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n,m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	sort(s.begin(),s.end());
	do
	{
	    bool ok = true;
	    rep(i,n-1)
		{
		    string s0 = s[i];
			string s1 = s[i+1];
			int count = 0;
			rep(j,m) count += s0[j] != s1[j];
			if(count > 1)
			{
			    ok = false;
				break;
			}
		}
		if(ok)
		{
	    	cout << "Yes" << endl;
		    return 0;
		}

	}while(next_permutation(s.begin(),s.end()));
	cout << "No" << endl;
    return 0;
}

