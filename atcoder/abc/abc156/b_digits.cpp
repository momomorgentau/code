//46
//abc_156_b_digits
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while (n > 0)
	{
		++ans;
		n /= k;
	}
	cout << ans << endl;
	return 0;
}
