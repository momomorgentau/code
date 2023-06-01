//----------------------------
// ABC 255 B 
// Star or Not
// 62
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;cin >> n;
	vector<int> d(n);
	rep(i,n-1)
	{
	    int a,b; cin >> a >> b;
		--a,--b;
		d[a]++;
		d[b]++;
	}
	rep(i,n)
	{
	    if(d[i] == 1 || d[i] == n-1) continue;
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;

    return 0;
}

