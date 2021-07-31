//ABC_108_C
//Triangular Relationship
//966
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n,k;
    cin >> n >> k;
    ll z = n/k;
    ll ans = z*z*z;
    if(k%2 == 0)
    {
        ll h = (n + k/2)/k;
        ans += h*h*h;
    }
    cout << ans << endl;
	return 0;
}