//42
//abc162b_fizzbuzz_sum
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	ll ans = 0;
	rep(i, n)
	{
		int m = i + 1;
		if (m % 3 == 0 || m % 5 == 0) continue;
		ans += m;
	}
	cout << ans << endl;
	return 0;
}
