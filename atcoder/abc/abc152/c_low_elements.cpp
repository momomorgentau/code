//171
//abc152_c_low_elements

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];

	int ans = 0;
	int tmn = 1e9;
	rep(i, n)
	{
		int tp = p[i];
		if (tmn < tp) continue;
		++ans;
		tmn = tp;
	}
	cout << ans << endl;

	return 0;
}