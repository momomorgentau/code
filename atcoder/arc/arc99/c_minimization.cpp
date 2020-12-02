//467
//c_minimization

include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main()
{
	int n, k;
	cin >> n >> k;
	int s = 0;
	int ans = 0;
	while (s < n - 1) s += k - 1, ++ans;
	cout << ans << endl;
}