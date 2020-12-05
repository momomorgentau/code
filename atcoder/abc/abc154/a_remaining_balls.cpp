//14
//abc_154_a_remaining_balls
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	string s, t, u;
	cin >> s >> t;
	int a, b;
	cin >> a >> b;
	cin >> u;
	if (u == s) --a;
	if (u == t) --b;
	cout << a << " " << b << endl;

	return 0;
}
