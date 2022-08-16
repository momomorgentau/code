//----------------------------
//ABC 263 A
//Full House
//27
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	vector<int> v(14, 0);
	++v[a];
	++v[b];
	++v[c];
	++v[d];
	++v[e];
	bool two = false;
	bool three = false;
	rep(i, 14)
	{
		two |= (v[i] == 2);
		three |= (v[i] == 3);
	}
	if (two && three) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}