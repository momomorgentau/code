//ABC_193_A_Discount
//9
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	double a, b;
	cin >> a >> b;
	double ans = 1.0 - (b / a);
	cout << ans*100 << endl;
	return 0;
}