//----------------------------
//ABC_094_D
//Binomial Coefficients
//867
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int l = 0, r = 0;
	l = *max_element(a.begin(), a.end());
	int rmx = 0;
	for (const auto& ai : a)
	{
		int now = min(ai,l-ai);
		if (rmx < now)
		{
			rmx = now;
			r = ai;
		}
	}
	cout << l << " " << r << endl;
	return 0;
}