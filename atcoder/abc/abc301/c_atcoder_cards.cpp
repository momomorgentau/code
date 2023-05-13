//----------------------------
// ABC 301 C 
// AtCoder Cards
// 
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string s,t;
	cin >> s >> t;
    vector<int> a(27), b(27);
	rep(i,s.size())
	{
	    if(s[i] == '@') a[26]++;
		else a[s[i]- 'a']++;
	}
	rep(i,t.size())
	{
	    if(t[i] == '@') b[26]++;
		else b[t[i]-'a']++;
	}
	int da = 0;
	int db = 0;
	string p = "atcoder";
	
	rep(i,26)
	{
	    bool at = false;
	    rep(j,p.size())
		{
		    at |= (i == p[j]-'a');
		}
		if(at)
		{
             if(a[i] < b[i]) da += (b[i] - a[i]);
			 if(b[i] < a[i]) db += (a[i] - b[i]);
		}
		else
		{
		    if(a[i] == b[i]) continue;
			cout << "No" << endl;
			return 0;
		}
	}
	if(da <= a[26] && db <= b[26]) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}

