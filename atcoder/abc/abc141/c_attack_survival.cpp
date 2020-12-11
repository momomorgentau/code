//135
//abc_141_c_attck_survival
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int n,k,q;
	cin >> n >> k >> q;
	vector<int> p(n,k);
	rep(i,q)
	{
		int ai; cin >> ai;
		--ai;
		++p[ai];
	}
	for(auto pi:p)
	{
		if(pi - q > 0)	cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}