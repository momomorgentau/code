//822
//arc103_c_/\/\/\/\/\
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int n;
	cin >> n;
	int nm = 100000;
	vector<int> o(nm, 0), e(nm, 0);
	rep(i, n)
	{
		int m;
		cin >> m;
		--m;
		if (i & 1) ++o[m];
		else ++e[m];
	}

	multiset<P> mso; //p<int,int> •p“xA”š
	multiset<P> mse;
	rep(i, nm)
	{
		mso.emplace(o[i], i);
		mse.emplace(e[i], i);
	}
	auto ito = mso.end();
	auto ite = mse.end();

	int o1 = (*--ito).second;
	int o2 = (*--ito).second;
	int e1 = (*--ite).second;
	int e2 = (*--ite).second;

	int cnto, cnte;
	if (o1 != e1)
	{
		cnto = o[o1];
		cnte = e[e1];
	}
	else if (o[o2] > e[e2])
	{
		//o2e1
		cnto = o[o2];
		cnte = e[e1];
	}
	else
	{
		//o1e2
		cnto = o[o1];
		cnte = e[e2];
	}
	int ans = n - cnto - cnte;
	cout << ans << endl;
	return 0;
}