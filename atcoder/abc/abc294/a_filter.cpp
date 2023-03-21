//----------------------------
//ABC 294 A
//Filter
//8
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
	rep(i, n)
	{
		int a; cin >> a;
		if (a % 2 == 0)
		{
			cout << a << " ";
		}
	}
	return 0;
}

