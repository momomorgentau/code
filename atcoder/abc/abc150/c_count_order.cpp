//422
//abc150_c_count_order
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
	int p = 0;
	int q = 0;
	int d = pow(10, n - 1);
	int td = d;
	rep(i, n)
	{
		int ci; cin >> ci;
		p += ci * td;
		td /= 10;
	}
	td = d;
	rep(i, n)
	{
		int ci; cin >> ci;
		q += ci * td;
		td /= 10;
	}

	vector<int> pq;
	rep(i, n) pq.emplace_back(i + 1);
	vector<int> s;
	do {
		int tpq = 0;
		int td = 1;
		rep(i, n)
		{
			tpq += pq[i] * td;
			td *= 10;
		}
		s.emplace_back(tpq);
	} while (next_permutation(pq.begin(), pq.end()));
	sort(s.begin(), s.end());

	int pi = distance(s.begin(), find(s.begin(), s.end(), p));
	int qi = distance(s.begin(), find(s.begin(), s.end(), q));
	int ans = abs(pi - qi);
	cout << ans << endl;
	return 0;
}