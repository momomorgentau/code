//ABC194A_I_Scream
//15
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int a, b;
	cin >> a >> b;
	int ans = 0;
	if (a+b >= 15 && b >= 8) ans = 1;
	else if (a+b >= 10 && b >= 3) ans = 2;
	else if (a+b >= 3) ans = 3;
	else ans = 4;
	cout << ans << endl;
	return 0;
}