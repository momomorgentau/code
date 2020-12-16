//28
//abc142_a_odds_of_oddness
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
	int odd = 0;
	reps(i, 1, n + 1)
	{
		if (i & 1) ++odd;
	}
	double ans = (double)odd / n;
	printf("%.7f\n", ans);
	return 0;
}