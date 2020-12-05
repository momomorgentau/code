//14
//abc_153_a_serval_vs_monster
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int h, a;
	cin >> h >> a;
	int ans = h / a;
	if (h % a != 0) ++ans;
	cout << ans << endl;

	return 0;
}
