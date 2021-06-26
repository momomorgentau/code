//038
//Large_LCM
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll a, b;
	cin >> a >> b;
	ll g = gcd(a, b);
	a /= g;
	if (a > (ll)1e18 / b) cout << "Large" << endl;
	else cout << a * b << endl;
	return 0;
}