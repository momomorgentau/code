//85
//abc_156_c_rally
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	int ans = 1e9;
	rep(i, 101)
	{
		int now = 0;
		int p = i;
		rep(j, n)
		{
			int c = abs(x[j] - p);
			now += c * c;
		}
		ans = min(ans, now);
	}
	cout << ans << endl;

	return 0;
}

