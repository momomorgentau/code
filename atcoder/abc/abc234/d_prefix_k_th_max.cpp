//----------------------------
//ABC_234_D
//Prefix K-th Max
//503
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
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	set<int> s;
	rep(i, k)
	{
		s.insert(p[i]);
	}
	auto it = s.begin();
	cout << *it << endl;
	reps(i, k, n)
	{
		s.insert(p[i]);
		if (*it < p[i])
		{
			++it;
		}
		cout << *it << endl;
	}
	return 0;
}