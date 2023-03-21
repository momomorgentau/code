//----------------------------
// ABC 294 D
// Bank
// 385
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n, q;
	cin >> n >> q;
	int called = 0;
	set<int> s;
	while (q--)
	{
		int e; cin >> e;
		if (e == 1)
		{
			s.insert(++called);
		}
		if (e == 2)
		{
			int x; cin >> x;
			s.erase(x);
		}
		if (e == 3)
		{
			printf("%d\n", *(s.begin()));
		}
	}
	return 0;
}

