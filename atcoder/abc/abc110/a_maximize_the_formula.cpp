//ABC_110_A
//Maximize_the_Formula
//?
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	vector<int> v(3);
	rep(i, 3) cin >> v[i];
	sort(v.rbegin(), v.rend());
	int ans = v[0] * 10 + v[1] + v[2];
	cout << ans << endl;
	return 0;
}