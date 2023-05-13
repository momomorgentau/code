//----------------------------
// ABC 301 A
// Overall Winner
// 8
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
    string s;
    cin >> n >> s;
    int takahashi = 0;
    int aoki = 0;
    rep(i,n) 
    {
	    if(s[i] == 'T') ++takahashi;
		else ++aoki;
    }
	if(takahashi > aoki)
	{
	    cout << "T" << endl;
	}
	else if(aoki > takahashi)
	{
	    cout << "A" << endl;
	}
	else
	{
	    rep(i,n)
		{
		    if(s[i] == 'T') --takahashi;
			else --aoki;
	
		if(takahashi == 0) 
		{
		    cout << "T" << endl;
			return 0;
		}
		if(aoki == 0)
		{
		    cout << "A" << endl;
			return 0;
		}
        }
	}
    return 0;
}
