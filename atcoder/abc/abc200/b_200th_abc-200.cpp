//ABC_200_B
//200th ABC-200
//20
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll n;
	int k;
	cin >> n >> k;
	while (k--)
	{
		if (n % 200 != 0) n = n * 1000 + 200;
		else n /= 200;
	}
	cout << n << endl;
	return 0;
}