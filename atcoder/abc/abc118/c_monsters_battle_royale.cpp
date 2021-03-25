//ABC_118_C_Monsters_Battle_Royale
//646
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	rep(i, n)
	{
		int a; cin >> a;
		ans = gcd(ans, a);
	}
	cout << ans << endl;
	return 0;
}