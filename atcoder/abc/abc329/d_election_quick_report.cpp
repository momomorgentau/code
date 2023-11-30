//----------------------------
// ABC 329 D
// Election Quick Report
// 263
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
	vector<int> d(n);
	set<P> s;
	rep(i,n) s.insert(make_pair(0, i));
	rep(i,m)
	{
	    int a; cin >> a;
		--a;
		int p = d[a];
		d[a]++;
		int q = d[a];
		s.erase(make_pair(-p, a));
		s.insert(make_pair(-q, a));
		P f = *s.begin();
		printf("%d\n", f.second + 1);
	}
    return 0;
}

