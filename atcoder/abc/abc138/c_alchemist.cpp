//116
//abc138_c_alchemist
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
	priority_queue<double, vector<double>, greater<double>> pq;

	rep(i, n)
	{
		int vi; cin >> vi;
		pq.emplace(vi);
	}

	double ans = 0;

	while (1)
	{
		double v1 = pq.top(); pq.pop();
		double v2 = pq.top(); pq.pop();
		ans = (v1 + v2) / 2;
		if (pq.empty()) break;
		else pq.emplace(ans);
	}
	printf("%.6f\n", ans);

	return 0;
}