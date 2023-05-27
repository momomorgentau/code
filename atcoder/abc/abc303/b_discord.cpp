//----------------------------
// ABC 303 B 
// Discord
// 112
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
	set<P> s;
	rep(i,n)rep(j,n)
	{
	    if(i >= j) continue;
		s.insert(make_pair(i,j));
	}
	rep(i,m)
	{
	     vector<int> a(n);
		 rep(j,n) cin >> a[j];
		 rep(j,n)a[j]--;
		 rep(j, n-1)
		 {
		     int x = a[j];
			 int y = a[j+1];
			 if(x > y) swap(x,y);
			 s.erase(make_pair(x,y));
		 }
	}
	cout << s.size() << endl;
    return 0;
}

