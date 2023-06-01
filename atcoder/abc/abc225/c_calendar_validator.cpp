//----------------------------
// ABC 225 C 
// Calendar Validator
// 326
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n,m;cin >> n >> m;
	vector<vector<int>> b(n,vector<int> (m));
	rep(i,n)rep(j,m) cin >> b[i][j];
	bool ok = true;
	rep(i,n)rep(j,m-1)
	{
	    if(b[i][j] != b[i][j+1] -1) ok = false;
	    if(b[i][j] % 7 == 0) ok = false;
	}

	rep(i,n-1)rep(j,m)
	{
	    if(b[i][j] != b[i+1][j] -7) ok = false;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}

