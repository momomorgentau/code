//----------------------------
// ABC 327 C 
// Number Plave
// 169
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    const int N = 9;
	const int M = (1 << N) -1;
	vector<vector<int>> a(N, vector<int> (N));
	rep(i,N)rep(j,N) cin >> a[i][j];
	rep(i,N)rep(j,N) --a[i][j];
	bool ng = false;
	// 横
	rep(i,N)
	{
	    int now = 0;
	    rep(j,N)	
		{
		    now |= 1 << a[i][j];
		}
		ng |= now != M; 
	}
	//縦
    rep(j,N)
	{
	    int now = 0;
		rep(i,N)
		{
		    now |= 1 << a[i][j];
		}
		ng |= now != M;
	}
	// 3*3
	vector<int> dxy = {0,3,6};
	for(const auto& dx: dxy)
	{
	    for(const auto&dy: dxy)
		{
		    int now = 0;
			rep(i,3)rep(j,3)
			{
			    now |= 1 << a[dx+i][dy+j];
			}
			ng |= now != M;
		}
	}
	if(!ng) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}

