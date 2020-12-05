//64
//abc_154_c_distinct_or_not
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	int n, r;
	cin >> n >> r;
	int ans = 0;
	if (n >= 10) ans = r;
	else ans = r + 100 * (10 - n);
	cout << ans << endl;
	return 0;

}
