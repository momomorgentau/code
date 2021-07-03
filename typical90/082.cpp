//082
//Counting Numbers
//*3

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using namespace std;

//‘½”{’·®”
#include <boost/multiprecision/cpp_int.hpp>
using Bint = boost::multiprecision::cpp_int;

const int mod = 1e9 + 7;

int main()
{
	Bint l, r;
	cin >> l >> r;
	Bint ans = 0;
	rep(i, 20)
	{
		Bint t = Bint(pow(10, i));
		if (r < t) break;
		if (t * 10 < l) continue;
		Bint tl = max(l, t);
		Bint tr = min(r, t * 10 - 1);
		ans += ((tr + 1) * tr / 2 - (tl - 1) * tl / 2) * (i + 1);
		ans %= mod;
	}
	cout << ans << endl;

}