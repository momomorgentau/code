//----------------------------
//ABC 236 B
//Who is missing?
//29
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
	int n;
	cin >> n;
	vector<int> a(n, 4);
	rep(i, 4 * n - 1)
	{
		int ai; cin >> ai;
		--ai;
		a[ai]--;
	}
	rep(i, n)
	{
		if (a[i] == 0) continue;
		cout << i + 1 << endl;
		break;
	}
	return 0;
}