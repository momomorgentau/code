//18
//abc138_a_red_or_not
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
	vector<double> a(n);
	for (auto& e : a) cin >> e;
	double ans = 0;
	for (auto ai : a) ans += 1 / ai;
	ans = 1 / ans;
	printf("%.6f\n", ans);
	return 0;
}
