//----------------------------
//ABC 245 E
//Wrapping Chocolate
//1571
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m), d(m);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, m) cin >> c[i];
	rep(i, m) cin >> d[i];
	priority_queue<T, vector<T>> pq;
	rep(i, n) pq.emplace(make_tuple(a[i], b[i], 0));
	rep(i, m) pq.emplace(make_tuple(c[i], d[i], 1));
	multiset<int> ms;
	bool ok = true;

	while (!pq.empty())
	{
		auto[x, y, p] = pq.top();
		pq.pop();
		if (p == 0)
		{
			auto it = ms.lower_bound(y);
			if (it != ms.end())
			{
				ms.erase(ms.find(*it));
			}
			else
			{
				ok = false;
			}
		}
		else
		{
			ms.insert(y);
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

