//----------------------------
//ABC_233_E
//Sigma[k=0...10^100]floor(X/10^k)
//969
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
	string x;
	cin >> x;
	reverse(x.begin(), x.end());
	string ans = "";
	ll s = 0;
	rep(i, x.size())
	{
		s += x[i] - '0';
	}
	ll rem = 0;
	rep(i, x.size())
	{
		rem += s;
		int a = rem % 10;
		ans += a + '0';
		s -= x[i] - '0';
		rem /= 10;
	}
	if (rem != 0)
	{
		string rs = to_string(rem);
		reverse(rs.begin(), rs.end());
		ans += rs;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
