//----------------------------
// ABC 293 B
// Call the ID Number
// 65
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i]--;
	vector<int> b(n);
	rep(i, n)
	{
		if (!b[i]) b[a[i]] = 1;
	}
	int k = 0;
	rep(i, n) k += !b[i];
	cout << k << endl;
	rep(i, n)
	{
		if (!b[i]) cout << i + 1 << " ";
	}
	return 0;
}
