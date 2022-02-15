//----------------------------
//ABC_094C
//Many Medians
//566
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
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector<int> y = x;
	sort(y.begin(), y.end());
	int l = y[y.size() / 2 - 1];
	int r = y[y.size() / 2];
	for (const auto& xi : x)
	{
		if (xi <= l)
		{
			printf("%d\n", r);
		}
		else
		{
			printf("%d\n", l);
		}
	}
	return 0;
}