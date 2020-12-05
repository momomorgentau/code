//15
//abc_154_b_i_miss_you
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	string s;
	cin >> s;
	string ans;
	rep(i, s.size())ans += "x";
	cout << ans << endl;

	return 0;
}
