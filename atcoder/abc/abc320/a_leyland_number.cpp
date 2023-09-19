//----------------------------
// ABC 320 A 
// Leyland Number
// 10
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll a,b;
	cin >> a >> b;
	ll ab = 1;
	ll ba = 1;
	rep(i,b) ab *= a;
	rep(i,a) ba *= b;
	cout << ab  + ba << endl;
    
    return 0;
}

