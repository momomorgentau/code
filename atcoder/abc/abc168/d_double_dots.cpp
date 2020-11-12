//750
//abc_d_double_dots
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1);
	rep(i, m) 
	{
		int a, b;
		cin >> a >> b;
		a, b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}


	vector<int> w(n+1, -1);
	queue<int> q;
	for (auto i : v[1])
	{
		q.emplace(i);
		w[i] = 1;
	}

	while (!q.empty())
	{
		int tq;
		tq = q.front();
		q.pop();

		for (int i : v[tq])
		{
			if (w[i] != -1) continue;
			w[i] = tq;
			for (auto j : v[i])
			{
				if (w[j] != -1) continue;
				q.push(i);
			}
		}

	}

	cout << "Yes" << endl;
	for (int i = 2; i < n + 1;++i) 
	{
		cout << w[i] << endl;
	}

	return 0;
}