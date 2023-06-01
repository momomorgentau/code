//----------------------------
// ABC 225 D 
// Play Train
// 778
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n,q;
	cin >> n >> q;
	vector<int> a(n,-1), b(n,-1);
	while(q--)
	{
	    int t; cin >> t;
		if(t == 1)
		{
		    int x,y;
			cin >> x >> y;
			--x,--y;
			b[x] = y;
			a[y] = x;
		}
		if(t == 2)
		{ 
		    int x,y;
			cin >> x >> y;
			--x,--y;
			b[x] = -1;
			a[y] = -1;
		}
		if(t == 3)
		{
		    int x;
			cin >> x;
			--x;
			while(a[x] != -1) x = a[x];
			vector<int> ans;
			while(x != -1) 
			{
			    ans.emplace_back(x+1);
				x = b[x];
			}
			printf("%d ", ans.size());
			for(const auto&c:ans) printf("%d ", c);
			printf("\n");
		}
	}
    return 0;
}

