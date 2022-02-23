//----------------------------
//ABC_239_C
//Knight Fork
//198
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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<int> dx{ 1,2,2,1,-1,-2,-2,-1 };
	vector<int> dy{ 2,1,-1,-2,-2,-1,1,2 };

	set<P> a1, a2;
	rep(i, dx.size())
	{
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		a1.insert(make_pair(nx1, ny1));
		a2.insert(make_pair(nx2, ny2));
	}
	bool ok = false;
	for (const auto& [xi, yi]:a1)
	{
		if(a2.count(make_pair(xi, yi)))
		{
			ok = true;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

}