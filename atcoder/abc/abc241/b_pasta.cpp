//----------------------------
//ABC 241 B
//Pasta
//42
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
	map<int, int> a;
	rep(i, n)
	{
		int ai; cin >> ai;
		a[ai]++;
	}
	bool ok = true;
	rep(i, m)
	{
		int bi; cin >> bi;
		if (a[bi] == 0)
		{
			ok = false;
			break;
		}
		a[bi]--;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}