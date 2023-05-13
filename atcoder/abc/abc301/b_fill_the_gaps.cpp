//----------------------------
// ABC 301 B 
// Fill the Gaps
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
    int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(i,n)
	{
	    cout << a[i] << " ";
		if(i == n-1) break;
	    for(int j = a[i]+1; j < a[i+1];j++)
		{
		    cout << j << " ";
		}
		for(int j = a[i]-1; j > a[i+1];j--)
		{
		    cout << j << " ";
		}
	}
    return 0;
}

