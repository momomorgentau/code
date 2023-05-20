//----------------------------
// ABC 302 A 
// Attack
// 24
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
	cout << (a+ b -1) / b << endl;
    return 0;
}

