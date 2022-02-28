//----------------------------
//ABC 232 C
//Graph Isomorphism
//685
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
	vector<set<int>> ab(n);
	vector<set<int>> cd(n);
	rep(i, m)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		ab[a].insert(b);
		ab[b].insert(a);
	}
	rep(i, m)
	{
		int c, d; cin >> c >> d;
		--c, --d;
		cd[c].insert(d);
		cd[d].insert(c);
	}
	vector<int> p;
	rep(i, n)
	{
		p.emplace_back(i);
	}
	bool ok = false;
	do
	{
		queue<int> q;
		vector<int> used(n, -1);
		int count = 0;
		rep(i, n)
		{
			if (used[i] == 1) continue;
			q.emplace(i);
			used[i] = 1;
			while (!q.empty())
			{
				int a = q.front();
				q.pop();

				for (const auto& e : ab[a])
				{
					if (cd[p[a]].count(p[e]))
					{
						++count;
					}
					if (used[e] == 1) continue;
					used[e] = 1;
					q.emplace(e);
				}
			}
		}

		if (count == 2 * m)
		{
			ok = true;
			break;
		}
	} while (next_permutation(p.begin(), p.end()));

	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}