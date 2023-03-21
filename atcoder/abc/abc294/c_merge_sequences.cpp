//----------------------------
// ABC 294 C
// Merge Sequences
// 127
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	map<int, int> mpa;
	map<int, int> mpb;

	rep(i, n) mpa[a[i]] = i;
	rep(i, m) mpb[b[i]] = i;

	vector<int> c;
	rep(i, n) c.emplace_back(a[i]);
	rep(i, m) c.emplace_back(b[i]);
	sort(c.begin(), c.end());

	vector<int> ansa(n);
	vector<int> ansb(m);
	rep(i, n + m)
	{
		if (mpa.count(c[i]))
		{
			ansa[mpa[c[i]]] = i + 1;
		}
		else
		{
			ansb[mpb[c[i]]] = i + 1;
		}
	}
	rep(i, n)
	{
		cout << ansa[i] << " ";
	}
	cout << endl;
	rep(i, m)
	{
		cout << ansb[i] << " ";
	}
	cout << endl;
	return 0;
}

