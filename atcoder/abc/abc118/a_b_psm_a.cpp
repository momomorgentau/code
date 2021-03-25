//ABC_118_A_B_+/-_A
//17
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int a, b;
	cin >> a >> b;
	int ans = a + b;
	if (b%a != 0) ans -= 2*a;
	cout << ans << endl;
	return 0;
}