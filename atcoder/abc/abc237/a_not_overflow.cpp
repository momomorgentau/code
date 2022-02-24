//----------------------------
//ABC_237_A
//Not Overflow
//25
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	ll n;
	cin >> n;
	ll B = 2LL << 30;
	if (-B <= n && n < B) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}